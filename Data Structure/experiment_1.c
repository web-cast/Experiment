#include <stdio.h>
#include <stdlib.h>
#include<time.h>

typedef struct Bstnode{         //Bst节点结构体
    int data;
    struct Bstnode *left;
    struct Bstnode *right;
}Bstnode;

/* void insert(Bstnode *root, int item)            //Bst插入建立
{
    Bstnode *parent=NULL, *current=root, *p;
    while(current!=NULL)
    {
        if(item>current->data){
            parent=current;
            current=current->right;
        }
        else{
            parent=current;
            current=current->left;
        }
    }
    p=(Bstnode *)malloc(sizeof(Bstnode));
    p->data=item;
    p->left=NULL;
    p->right=NULL;
    if(parent==NULL){
        root=p;
    }
    else if(parent->data>item)
        parent->left=p;
    else
        parent->right=p;
} */

void insert(Bstnode *root, int item)
{
    if(root)
    {
        if(root->data>item) insert(root->left,item);
        else insert(root->right,item);
    }
    else{
        root=(Bstnode *)malloc(sizeof(Bstnode));
        root->data=item;
        root->right=root->left=NULL;
    }
}

int inorder_traversal(Bstnode *root)            //中序遍历
{
    if(root==NULL){
        printf("1\n");
        return 0;
    }
    printf("%d ",root->data);
    inorder_traversal(root->right);
    inorder_traversal(root->left);
    return 1;
}

int search(Bstnode *root, int item)             //BST查找节点
{
    int n=1;
    Bstnode *p=root;
    if(root=NULL){
        return 0;
    }
    while(p->data!=item)
    {
        if(p->data>item){
            p=p->left;
        }
        else{
            p=p->right;
        }
        n++;
    }
    if(p->data==item){
        printf("查找成功，操作次数为%d!\n",n);
    }
    else{
        printf("查找失败，操作次数为%d!\n",n);
    }
    return n;
}

int Delete(Bstnode *root, int item, int n)             //BST节点删除
{
	Bstnode *p=root, *parent=NULL, *t;
    if(root==NULL){
        printf("请先建立BST树\n");
        return 0;
    }
    while(p->data!=item)
    {
        if(p->data>item){
            parent=p;
            p=p->left;
        }
        else{
            parent=p;
            p=p->right;
        }
        n++;
    }
    if(p->left==NULL && p->right==NULL){
        n++;
        free(p);
    }
    else if(p->left==NULL && p->right!=NULL){
        n++;
        if(parent->data>p->data){
            parent->left=p->right;
        }
        else{
            parent->right=p->right;
        }
    }
    else if(p->right==NULL && p->left!=NULL){
        n++;
        if(parent->data>p->data){
            parent->left=p->left;
        }
        else{
            parent->right=p->left;
        }
    }
    else{
        t=p;
        for(p=p->right; p->left; p=p->left)
        t->data=p->data;
        n=Delete(t->right, t->data, n);
    }
    return n;
}

int main()
{
    int i = 0,A[50], s, n=0; 
    Bstnode *root=NULL;
	for(i = 0; i < 50; ++i){
		A[i]=rand()%800+200;         //随机生成50个200-1000内的整数
        printf("%d ",A[i]);
        insert(root, A[i]);
    }
    if(root==NULL){
        printf("%d\n",1999);
    }
    printf("中序遍历如下\n");
    inorder_traversal(root);
    printf("\n\n请输入需要查找的关键字：");
    scanf("%d",&s);
    search(root,s);
    printf("\n请输入需要删除的关键字：");
    scanf("%d",&s);
    n=Delete(root,s,n);
    printf("操作次数为%d\n",n);
    printf("\n中序遍历如下\n");
    inorder_traversal(root);
}
