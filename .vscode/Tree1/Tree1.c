#include<stdio.h>
#include<stdlib.h>
typedef enum PointerTag{Link,Thread};//Link==0指针，Thread==1线索
typedef int Elemtype;
//二叉树的二叉线索存储表示
typedef struct BiThrNode{
    Elemtype data;
    struct BiThrNode *lchild,*rchild;//左右孩子的指针

}BiThrNode,*BiThrNode;
