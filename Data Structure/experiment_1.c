#include <stdio.h>
#include <stdlib.h>
#include<time.h>

typedef struct Bstnode{         //Bst�ڵ�ṹ��
    int data;
    struct Bstnode *left;
    struct Bstnode *right;
}Bstnode;

void insert(Bstnode *root, int item)            //Bst���뽨��
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

int inorder_traversal(Bstnode *root)            //�������
{
    if(root==NULL){
        return 0;
    }
    printf("%d ",root->data);
    inorder_traversal(root->right);
    inorder_traversal(root->left);
}

int search(Bstnode *root, int item)             //BST���ҽڵ�
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
        printf("���ҳɹ�����������Ϊ%d!\n",n);
    }
    else{
        printf("����ʧ�ܣ���������Ϊ%d!\n",n);
    }
    return n;
}

int delete(Bstnode *root, int item, int n)             //BST�ڵ�ɾ��
{
    if(root==NULL){
        printf("���Ƚ���BST��\n");
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
		A[i]=(int) (round(1.0 * rand() / RAND_MAX * 800 + 200));            //�������50��200-1000�ڵ�����
        insert(root, A[i]);
    }
    printf("�����������\n");
    inorder_traversal(root);
    printf("\n\n��������Ҫ���ҵĹؼ��֣�");
    scanf("%d",&s);
    search(root,s);
    printf("\n��������Ҫɾ���Ĺؼ��֣�");
    scanf("%d",&s);
    n=delete(root,s,n);
    printf("��������Ϊ%d\n",n);
    printf("\n�����������\n");
    inorder_traversal(root);
}
