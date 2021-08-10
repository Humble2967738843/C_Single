#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node
{
	char data;//存储数据
	struct Node *LChild;//左儿子
	struct Node *RChild;//右儿子
}BNode,*BTree;

void CreatBTree(BTree * T)//创建二叉树 
{
	char ch;
	ch=getchar();
	if(ch=='#'){
		*T=NULL;
	}else{
		*T=(BTree )malloc(sizeof(BNode));
		(*T)->data=ch;
		CreatBTree(&((*T)->LChild));
		CreatBTree(&((*T)->RChild));	
	}
}

void PreOrder(BTree T)//先序遍历 
{
	if(T){
		printf("%c ",T->data);
		PreOrder(T->LChild);
		PreOrder(T->RChild);
	}
}

void InOrder(BTree T)//中序遍历 
{
	if(T){
		InOrder(T->LChild);
		printf("%c ",T->data);
		InOrder(T->RChild);
	}
} 

void PostOrder(BTree T)//后序序遍历 
{
	if(T){
		PostOrder(T->LChild);
		PostOrder(T->RChild);
		printf("%c ",T->data);
	} 
} 
void printleaves(BTree T){
    if(T){
       if(T->LChild==NULL&&T->RChild==NULL){
        printf("%c ",T->data);
       }
       printleaves(T->LChild);
       printleaves(T->RChild);
    }
}
int PostOrderGetHeight(BTree T){
    int HL,HR,MaxH;
    if(T){
        HL=PostOrderGetHeight(T->LChild);//求左子树的深度
        HR=PostOrderGetHeight(T->RChild);//求右子树的深度
        MaxH=(HL>HR)?HL:HR;
        return (MaxH+1);
    }else{
        return 0;//空树深度为零
    }
}
int main()
{
	BTree bt;
	
	printf("输入二叉树的节点数据\n");
	CreatBTree(&bt);
    printf("先序遍历结果为\n");
	PreOrder(bt);
    printf("\n");
	printf("中序遍历结果为\n");
	InOrder(bt);
    printf("\n");
	printf("后序遍历结果为\n");
	PostOrder(bt);
    printf("\n");
    printf("该树的叶子结点为\n");
    printleaves(bt);
    printf("\n");
    printf("该树的深度为\n");
    printf("%d",PostOrderGetHeight(bt));
	return 0;
} 