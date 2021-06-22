#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 50
typedef int KeyType;
KeyType a[N];

typedef struct BSTNode
{
	KeyType key;
	struct BSTNode *Lchild,*Rchild;
}BSTree;

void Create_RandomArray()
{
	int i;
	srand((int)time(NULL)); 
		
	for(i=0;i<N;i++)
		a[i]=rand() % 800 + 200;

	for(i=0;i<N;i++)
	{
		printf("%4d ",a[i]);
		if((i+1)%10==0)
			printf("\n");
	}
}			

void insert(BSTree *T,KeyType key)
{  
	BSTree *x,*p,*q;
	x=(BSTree*)malloc(sizeof(BSTree));
	x->key=key; 
	x->Lchild=x->Rchild=NULL;
	if (T==NULL)  
		T=x; 
	else  
	{  
		p=T;
		while (p)
		{  
			if (p->key == key) 
			{ 
				printf("�ؼ���Ϊ%d�Ľ���Ѵ���!\n",key); 
				break;
			}
		   else
		   {  
			  q=p; 
			  if (key < p->key)  
				  p=p->Lchild;
			  else 
				  p=p->Rchild; 
		   }
		}
		if (x->key < q->key)  
			q->Lchild=x;
		else 
			q->Rchild=x;
	}
}
BSTree *CreateBST()
{
	BSTree *T;
	int i;

	T=(BSTree*)malloc(sizeof(BSTree));
	T->key=a[0];
	T->Lchild=T->Rchild=NULL;

	for(i=1;i<N;i++)
		insert(T,a[i]);
	printf("\nBST�������ɹ�!");
	return T;	
}
void contains(BSTree *T)
{
	BSTree *p=T;
	KeyType key;
	int n=0;
	printf("��������Ҫ���ҵĹؼ���:");
	scanf("%d",&key);

	while (p && (p->key!=key))
	{
		n++;
		if (key < p->key) 
		{
			n++;
			p=p->Lchild;
		}
		else
		{
			n++;
			p=p->Rchild;
		}
	}
	if (p==NULL) 
		printf("�ؼ���%d������!\n",key);
	else
		printf("���ҳɹ�!\n");
}
void Delete(BSTree *T)
{  
	BSTree *p=T,*f=NULL,*q,*s;
	KeyType key;
	int n=0;
	printf("��������Ҫɾ���Ĺؼ���:");
	scanf("%d",&key);

	while(p && (p->key!=key))
	{  
		f=p;
		if (key < p->key) 
			p=p->Lchild;  
		else 
			p=p->Rchild;
	}
	if(p==NULL)
		printf("�ؼ���%d������!\n",key); 
	else
	{  
		s=p;   
		if(p->Lchild && p->Rchild) 
		{ 
			f=p; 
			s=p->Lchild;         
			while(s->Rchild)
			{  
				f=s; 
				s=s->Rchild;  
			}
			p->key=s->key; 
		}  
		if(s->Lchild)
			q=s->Lchild;
		else
			q=s->Rchild;
		if(f==NULL)  
			T=q;
		else if(f->Lchild==s) 
			f->Lchild=q;
		else
			f->Rchild=q;
		free(s);
		printf("�ؼ���%dɾ���ɹ�!",key);
	}
}
void InorderTraverse(BSTree *T)
{  
	if (T!=NULL) 
	{  
		InorderTraverse(T->Lchild);
		printf("%4d ",T->key);
		InorderTraverse(T->Rchild);
	}
}
int main(void)
{
	BSTree *T=(BSTree*)malloc(sizeof(BSTree));
	int i,choice;
	printf("�������������%d����[200,1000]֮�以����ͬ��������\n",N);
	Create_RandomArray();
	
	do
	{
		printf("\n=============================================================\n");
		printf("|  1 - ����BST����������������㷨������\n");
		printf("|  2 - ����BST����ָ���Ĺؼ���\n");
		printf("|  3 - ɾ��BST����ָ���Ĺؼ���\n");
		printf("|  4 - �˳�����");
		printf("\n=============================================================\n");
		do
		{
			scanf("%d",&choice);
		}while(choice<1 || choice>4);

		switch(choice)
		{
			case 1:				
					T=CreateBST();
					printf("�����������Ϊ:\n");
					InorderTraverse(T);
					printf("\n");
					break;
			case 2:
					contains(T);
					break;
			case 3:
					Delete(T);
					break;
			case 4:
					break;
		}
	}while(choice!=4);
}
