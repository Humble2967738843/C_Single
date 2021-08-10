#include<stdio.h>
#include<stdlib.h>

#define MAX_NODE 50
typedef int Elemtype; 
typedef struct BTNode{
	Elemtype Data;
	struct BTNode *Lchild,*Rchild;
}BTNode; 
void createBiTree(BTNode *T){
	char ch=' ';
	scanf("%c",&ch);
	//getchar();

	if(ch=='#'){
		T=NULL;
	}else{
		if(!(T=(BTNode*)malloc(sizeof(BTNode)))){
			printf("申请空间失败\n");
			return;
		}
		T->Data=ch;
		createBiTree(T->Lchild);
		createBiTree(T->Rchild);
	}
	return;
}
//先序遍历 
void PreTraverse(BTNode *T){
	BTNode *Stack[MAX_NODE],*p=T,*q;
	int top=0;
	if(T==NULL){
		printf("Binary id Empty!\n");
	}else{
		do{
			printf("%c",p->Data);
			q=p->Rchild;
			if(q!=NULL){
				Stack[++top]=q;
			}
			p=p->Lchild;
			if(p==NULL){
				p=Stack[top];
				top--;
			} 
		}while(p!=NULL);
	}
}
//中序遍历 
void InorderTraverse(BTNode *T){
	BTNode *stack[MAX_NODE],*p=T;
	int top=0,flag=1;
	if(T==NULL){
		printf("Binary tree is empty!");
	}else{
		do{
			while(p!=NULL){
				stack[++top]=p;
				p=p->Lchild;
			}
			if(top==0){
				flag=0;
			}else{
				p=stack[top];
				top--;
				printf("%c",p->Data);
				p=p->Rchild;
				}
			}while(flag!=0);
	
   }
}
//后序遍历
void PostOrederTraavese(BTNode *T){
	BTNode *S1[MAX_NODE],*p=T;
	int S2[MAX_NODE],top=0,flag=1;
	if(T==NULL){
		printf("Binary Tree is Empty!\n");
	}else{
		do{
			while(p!=NULL){
				S1[top++]=p;
				S2[top]=0;
				p=p->Lchild;
			}
			if(top==0){
				flag=0;
			}else if(S2[top]==0){
				p=S1[top]->Rchild;
				S2[top]=1;
			}else{
				p=S1[top];
				top--;
				printf("%c",p->Data);
				p=NULL;
			}
		}while(flag!=0);
	}
} 
//层次遍历
void LevelorderTraverse(BTNode *T){
	BTNode *Queue[MAX_NODE],*p=T;
	int front=0,real=0;
	if(p!=NULL){
		Queue[++real]=p;
		while(front<real){
			p=Queue[++front];
			printf("%c",p->Data);
			if(p->Lchild!=NULL){
				Queue[++real]=p->Lchild;
			}
			if(p->Rchild!=NULL){
				Queue[++front]=p->Rchild;
			}
		}
	}
} 
//应用1-输出所有节点

//统计节点数目
int PreOrderNum(BTNode  *T){
	int count=0;
      if(T!=NULL){
        if(T->Lchild==NULL&&
        T->Rchild==NULL) {
        	printf("%c",T->Data);
        	count++;
		}
        PreOrderNum(T->Lchild);
        PreOrderNum(T->Rchild);
	}   
	return count;                    
} 
//求树的高度 
int  search_depth( BTNode  *T){
    BTNode  *Queue[MAX_NODE] ,*p=T;
    int  front=0 , rear=0, depth=0, level ;
// level总是指向访问层的最后一个结点在队列的位置
    if  (T!=NULL){
	   Queue[++rear]=p;    /*   根结点入队  */
       level=rear ;    /*  根是第1层的最后一个节点  */
       while (front<rear){
	     p=Queue[++front]; /*根结点出队*/
         if (p->Lchild!=NULL)
          Queue[++rear]=p->Lchild;    /*   左结点入队  */
         if (p->Rchild!=NULL)
          Queue[++rear]=p->Rchild;    /*   右结点入队  */
         if (front==level){ //  正访问的是当前层的最后一个结点  
	        depth++;
		    level=rear;    
		 }
      }
   }   
   return depth;
}
int main(){
	BTNode TT;
	printf("创建二叉树，输入?代表该节点为空\n");
	createBiTree(&TT);
	printf("先序遍历结果\n");
	PreTraverse(&TT);
	printf("中序遍历结果\n");
	InorderTraverse(&TT);
	printf("后序遍历结果\n");
	PostOrederTraavese(&TT);
	printf("该树的层序遍历结果为\n");
	LevelorderTraverse(&TT);
	printf("该树的所有叶子节点为\n");
	PreOrder(&TT);
	printf("该树的结点数目为\n");
	PreOrderNum(&TT);
	printf("该树的深度为\n");
	return 0;
}