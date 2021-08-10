#include<stdio.h>
#include<stdlib.h>
#define MaxSzie  100//存储数据元素的最大个数
typedef int Elemtype;
typedef struct TNode *Position;
typedef Position BinTree;//二叉树类型
struct TNode{
    Elemtype Data;//结点数据
    BinTree Left;//指向左子树
    BinTree Right;//指向右子树
};
//队列
struct QNode{
    Elemtype Data[MaxSzie];
    int rear;
    int front;
};
typedef struct QNode *Queue;
//先序遍历
void PreOrderTraversal(BinTree BT){
    if(BT){
        printf("%d",BT->Data);
        PreOrderTraversal(BT->Left);
        PreOrderTraversal(BT->Right);
    }
}
//中序遍历
void InOrderTraversal(BinTree BT){
    if(BT){
        InOrderTraversal(BT->Left);
        printf("%d",BT->Data);
        InOrderTraversal(BT->Right);
    }
}
//后序遍历
void PostOrderTraversal(BinTree BT){
    if(BT){
        InOrderTraversal(BT->Left);
        InOrderTraversal(BT->Right);
        printf("%d",BT->Data);
    }
}
//队列算法
//入队
void Add(Queue PtrQ,Elemtype item){
    if((PtrQ->rear+1)%MaxSzie==PtrQ->front){
        printf("队列满");
        return;
    }
    PtrQ->rear=(PtrQ->rear+1)%MaxSzie;
    PtrQ->Data[PtrQ->rear]=item;
}
//出队
Elemtype Delete(Queue PtrQ){
    if(PtrQ->front==PtrQ->rear){
        printf("队列空");
        return -100;
    }else{
        PtrQ->front=(PtrQ->front+1)%MaxSzie;
        return PtrQ->Data[PtrQ->front];
    }
}
//层序遍历
void LevelOrderTraversal(BinTree BT){
    Queue Q;
    BinTree T;
    if(!BT){
        return;//若是空树，直接返回
    }
    Q=CreatQueue(MaxSzie);//创建并初始化队列Q
    Add(Q,BT);
    while(!IsEmpty(Q)){
        T=Delete(Q);
        printf("%d\n",T->Data);//访问取出队列的节点
        if(T->Left) Add(Q,T->Left);
        if(T->Right) Add(Q,T->Right);
    }
}
//输出叶子节点
void PreOrderPrintLeaves(BinTree BT){
    if(BT){
        if(!BT->Left&&!BT->Right){
            printf("%d",BT->Data);
            PreOrderPrintLeaves(BT->Left);
            PreOrderPrintLeaves(BT->Right);
        }
    }
}
//求二叉树的高度
int PostOrderGetHeight(BinTree BT){
    int HL,HR,MaxH;
    if(BT){
        HL=PostOrderGetHeight(BT->Left);
        HR=PostOrderGetHeight(BT->Right);
        MaxH=(HL>HR)?HL:HR;
        return MaxH+1;
    }
}



