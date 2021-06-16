#include <stdio.h>
#include <stdlib.h>
#include<time.h>

typedef struct Bstnode{         //Bst树节点结构体
    int data;
    struct Bstnode *left;
    struct Bstnode *right;
}Bstnode;

void insert(Bstnode *root, int item)            //Bst树的建立（通过插入）
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
        root=parent;
    }
    else if(parent->data>item)
        parent->left=p;
    else
        parent->right=p;
}

int inorder_traversal(Bstnode *root)            //中序递归遍历
{
    if(root==NULL){
        return 0;
    }
    printf("%d ",root->data);
    inorder_traversal(root->right);
    inorder_traversal(root->left);
}

int search(Bstnode *root, int item)             //BST数查找节点
{
    int n=1;
    Bstnode *p=root;
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
        printf("查找成功，操作次数为：%d\n",n);
    }
    else{
        printf("不存在该节点，操作次数为%d!\n",n);
    }
    return n;
}

int delete(Bstnode *root, int item, int n)             //BST树删除节点
{
    if(root==NULL){
        printf("请先建立二叉树！\n");
        return 0;
    }
    Bstnode *p=root, *parent=NULL, *t;
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
        n=delete(t->right, t->data, n);
    }
    return n;
}

int main()
{
    srand((unsigned)time(NULL));
    int i = 0,A[50], s, n=0; 
    Bstnode *root=NULL;
	for(i = 0; i < 50; ++i){
		A[i]=(int) (round(1.0 * rand() / RAND_MAX * 800 + 200));            //产生200到1000之间的随机数
        insert(root, A[i]);
    }
    printf("中序遍历如下：\n");
    inorder_traversal(root);
    printf("\n\n请输入需要查找的关键字：");
    scanf("%d",&s);
    search(root,s);
    printf("请输入需要删除的关键字：");
    scanf("%d",&s);
    n=delete(root,s,n);
    printf("操作成功，操作次数为%d\n",n);
    printf("\n中序遍历如下：\n");
    inorder_traversal(root);
}
