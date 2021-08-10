#include<iostream>
using namespace std;

const int N=110;
int n;
typedef struct Node{
    Node *left,*right;
    char data;
}*Tree;
char c;

void build(Tree &T)
{
    cin>>c;
    if(c=='#'){T=NULL;return;}

    T=new Node;

    T->data=c;
    build(T->left);
    build(T->right);
}

void inorder(Tree &T)
{
    if(T==NULL) return;

    inorder(T->left);
    cout<<T->data<<" ";
    inorder(T->right);
}

int main()
{
    Tree T;
    build(T);
    inorder(T);
    return 0;
} 