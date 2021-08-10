#include<stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn = 26 + 10;
char pre[maxn];
char in[maxn];
int len;
struct BiNode{
    char data;
    BiNode* lchild;
    BiNode* rchild;
}; 
BiNode* build(int L1,int R1,int L2,int R2){
    if(L1>R1) return NULL;
    BiNode* root = new BiNode();
    root->data = pre[L1]; 
    int p=0;
    while(in[p]!=root->data) p++;
    int llen = p-L2;
    root->lchild = build(L1+1,L1+llen,L2,p-1);
    root->rchild = build(L1+llen+1,R1,p+1,R2);
    return root;
}
void postOrder(BiNode* root){
    if(root!=NULL){
        postOrder(root->lchild);
        postOrder(root->rchild);
        cout<<root->data;
    }
} 
int main(){
    while(gets_s(pre)!=NULL){
        len=strlen(pre);
        gets_s(in);
        BiNode* root = build(0,len-1,0,len-1);
        postOrder(root);
        cout<<endl;
    }
    return 0;
}