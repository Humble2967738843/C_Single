#include"string.h"
#include"malloc.h"
#define EqualFun strcmp
#define SetValue strcpy
#include<stdio.h>
#include<stdlib.h>
#define NAMESIZE 20
#define TRUE 1
#define FALSE 0
typedef int STATUS;
typedef char NODE[NAMESIZE];
struct BROTHERNODE{
	NODE node;
	struct BROTHERNODE *next;
};
typedef struct BROTHERNODE *BROTHER;
struct PARENTNODE{
	NODE node;
	BROTHER children;
};
typedef struct PARENTNODE PARENT;
struct TREENODE{
	PARENT node;
	struct TREENODE *next;
};
typedef struct TREENODE *TREE;
int Equal(NODE n1,NODE n2,int *fun()){
	return (int)fun(n1,n2);
}
void Set(NODE n1,NODE n2,void *fun()){
	fun(n1,n2);
}
BROTHER AddABRother(BROTHER br,NODE node){
	BROTHER b,pb;
	b=(BROTHER)malloc(sizeof(struct BROTHERNODE));
	Set(b->node,node,SetValue);
	if(br==NULL){
		br=b;
	}else{
		pb=br;
		while(pb->next){
			pb=pb->next;
		}
		pb->next=b;
	}
	return br;
}
TREE Form_Pa_Ch(NODE pa,BROTHER br){
	TREE parent;
	parent=(TREE)malloc(sizeof(struct TREENODE));
    strcpy(parent->node.node,pa);//	Set(parent->node.node,pa,Setvalue);//strcpy(parent->node.node,pa);
	parent->node.children=br;
	parent->next=NULL;
	return parent;
}
TREE AddAsubTree(TREE tree,TREE subtree){
	TREE t=tree;
	if(tree==NULL){
		tree=subtree;
	}else{
		while(t->next){
			t=t->next;
		}
		t->next=subtree;
	}
	return tree;
}
BROTHER ClearBrothers(BROTHER br){
	BROTHER br1=br;
	while(br){
		br1=br;
		br=br->next;
		free(br1);
	}
	return br;
}
TREE ClearTree(TREE tree){
	TREE tree1=tree;
	while(tree){
		tree1=tree;
		tree=tree->next;
		free(tree1);
	}
	return tree;
}
void CreateStr(char *brotherset){
	char *c=brotherset;
	while(*c){
		if(*c=='/'){
			*c='\0';
		}
		c++;
	}
	c++;
	*c='\0';
}
BROTHER CreateBrothers(BROTHER brothers,char *brotherset){
	char *p=brotherset;
	NODE node;
	CreateStr(brotherset);
	while(*p){
		Set(node,p,p);//strcpy(node,p);
		brothers=AddABrother(brothers,node);
		p+=strlen(node)+1;
	}
	return brothers;
}
TREE CreateTree(TREE tree,char *filename){
	TREE subtree;
	BROTHER brothers;
	FILE *fp;
	char parent[200],brotherset[5000];
	fp=fopen(filename,"r");
	while(!feof(fp)){
		fscanf(fp,"%s",parent);
		fscanf(fp,"%s",brotherset);
		brothers=NULL;
		brothers=CreateBrothers(brothers,brotherset);
		subtree=Form_Pa_Ch(parent,brothers);
		tree=AddAsubTree(tree,subtree);
	}
	fclose(fp);
	return tree;
}
BROTHER CopyBrothers(BROTHER children){
	BROTHER copynode,lastnode,head=NULL;
	while(children){
		copynode=(BROTHER)malloc(sizeof(struct BROTHERNODE));
	//	Set(copynode->node,copynode->node,children->node);
	    copynode->next=NULL;
	    if(head==NULL){
	    	head=copynode;
		}else{
			lastnode->next=copynode;
		}
		lastnode=copynode;
		children=children->next;
	}
	return head;
}
BROTHER ExpandNodes(TREE tree,NODE pa){
	BROTHER children=NULL;
	TREE t=tree;
	while(t){
		if(Equal(t->node.node,pa,EqualFun)==0){
			children=CopyBrothers(t->node.children);
			break;
		}
		t=t->next;
	}
	return children;
}
typedef struct BROTHERNODE *STACK;
STACK PushChildren(STACK stack,BROTHER children){
	BROTHER p,head;
	head=CopyBrothers(children);
	p=head;
	if(p!=NULL){
		while(p->next){
			p=p->next;
		}
		p->next=stack;
		stack=head;
	}
	return stack;
}
STACK PopAChild(STACK stack,NODE child){
	STACK p=stack;
	if(p!=NULL){
		Set(child,p->node,SetValue);
		stack=p->next;
		free(p);
	}
	return stack;
}
STACK ClearStack(STACK stack){
	stack=ClearBrothers((BROTHER)stack);
	return stack;
}
STATUS Search(TREE tree,NODE start,NODE end){
	TREE pnode;
	NODE node;
	BROTHER children;
	STACK stack;
	STATUS flag=FALSE;
	if(tree==NULL){
		return flag;
	}
	stack=(STACK)malloc(sizeof(struct BROTHERNODE));
	stack->next=NULL;
	Set(stack->node,start,SetValue);
	while(stack){
		stack=PopAChild(stack,node);
		if(Equal(end,node,EqualFun)==0){
			flag=TRUE;
			break;
		}
		children=ExpandNodes(tree,node);
		stack=PushChildren(stack,children);
	}
	ClearStack(stack);
	return flag;
}
void main(){
	NODE start,end;
	TREE tree;
	STATUS flag;
	char *filename="C:\\Users\\YL\\Desktop";
	tree=CreateTree(tree,filename);
	printf("The Start Node:");
	scanf("%s",start);
	printf("The End Node");
	scanf("%s",end);
	flag=Search(tree,start,end);
	printf("Search %s from %s, Status=%d\n",end,start,flag);
	printf("======================================");
	ClearTree(tree);
}
