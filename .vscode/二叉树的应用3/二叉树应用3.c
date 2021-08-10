#include<stdio.h>
#include<stdlib.h>
#define _Data char
#define _ArrayMaxSize 100

typedef struct TreeNode{
    _Data value;
    struct TreeNode * father;
    struct TreeNode * right;
    struct TeenNode * left;
}* pNode, Node;

pNode createNode(_Data value);//创建节点
void printTree(pNode father);//树打印器
int getHigh(pNode father);//获得树高
void destoryTree(pNode father);//销毁树
void createByLeft(pNode father);//创建树
void printByFirst(pNode father);//先序打印
void printByCenter(pNode father);//中序打印
void printByEnd(pNode father);//后序打印

pNode createNode(_Data value) {
    pNode node = (pNode) malloc(sizeof(Node));
 
    node->father = NULL;
    node->left = NULL;
    node->right = NULL;
    node->value = value;
 
    return node;
}
 
void createByLeft(pNode father) {
    _Data value;
    scanf("%c", &value);
    if (value != '#') {
        pNode left = createNode(value);
        father->left = left;
        createByLeft(left);
    }
 
    scanf("%c", &value);
    if (value != '#') {
        pNode right = createNode(value);
        father->right = right;
        createByLeft(right);
    }
}
 
void destoryTree(pNode father) {
    if (father->right != NULL) {
        destoryTree(father->right);
    }
    if (father->left != NULL) {
        destoryTree(father->left);
    }
 
    free(father);
}
 
int getHigh(pNode father) {
    int left = 1, right = 1;
    if (father->left != NULL) {
        left += getHigh(father->left);
    }
 
    if (father->right != NULL) {
        right += getHigh(father->right);
    }
 
    return left>right?left:right;
}
 
void printTree(pNode father) {
    pNode res[_ArrayMaxSize];   //存储列队
    int f = 0, r = 0;   //前指针 后指针
    res[f++] = father;
    int count = 0;
    int heigh = getHigh(father) + 1;
    while(r != f){
//        树循环
        pNode cRes[_ArrayMaxSize];   //打印队列
        int cf = 0, cr = 0;
        while(r != f){
            cRes[cf++] = res[(r++)%_ArrayMaxSize];
        }
 
        int spaceS = (1 << (heigh - count))+ (heigh - count) - 1;
        for(int i = 0; i < spaceS; i++) printf(" ");
 
        int flag = 1;
        while(cr != cf){
 
            //层循环
            pNode temp = cRes[cr++];
            if(temp != NULL){
                res[(f++)%_ArrayMaxSize] = temp->left;
                res[(f++)%_ArrayMaxSize] = temp->right;
                printf("%c", temp->value);
            } else{
                printf("#");
            }
            if(flag > 0){
                for(int j = (1 << (heigh - count + 1)); j >= 0; j--) printf(" ");
            }else{
                for(int j = (1 << (heigh - count + 1)); j > 1; j--) printf(" ");
            }
            flag *= -1;
 
        }
        printf("\n");
        count++;
    }
 
}
 
void printByFirst(pNode father){
    if(father != NULL){
        printf("%c", father->value);
        if(father->left != NULL){
            printByFirst(father->left);
        }
        if(father->right != NULL){
            printByFirst(father->right);
        }
    }
}
 
void printByCenter(pNode father){
    if(father != NULL){
        if(father->left != NULL){
            printByFirst(father->left);
        }
        printf("%c", father->value);
        if(father->right != NULL){
            printByFirst(father->right);
        }
    }
 
}
 
void printByEnd(pNode father){
    if(father != NULL){
        if(father->left != NULL){
            printByFirst(father->left);
        }
        if(father->right != NULL){
            printByFirst(father->right);
        }
        printf("%c", father->value);
    }
}

int main() {
    pNode node  = createNode('#');
 
    createByLeft(node);
 
    printf("树的高度：%d\n", getHigh(node));
    printf("先序输出:");
    printByFirst(node);
    printf("\n先序输出:");
    printByCenter(node);
    printf("\n先序输出:");
    printByEnd(node);
 
    printf("\n");
    printTree(node);
 
    destoryTree(node);
}
