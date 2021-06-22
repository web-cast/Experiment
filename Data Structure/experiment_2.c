#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Hash{
    int data;
    struct Hash *next;
}Hash;

int add_data(Hash a[19], int item)          //哈希表的建立
{
    int n;
    Hash *p,*q;
    n=item%19;
    if(a[n].data==-1){
        a[n].data=item;
    }
    else if(a[n].next==NULL){
        p=(Hash *)malloc(sizeof(Hash));
        p->next=NULL;
        p->data=item;
        a[n].next=p;
    }
    else{
        p=a[n].next;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        q=(Hash *)malloc(sizeof(Hash));
        q->next=NULL;
        q->data=item;
        p->next=q;
    }
    return 1;
}

int search(Hash a[19],int item)             //哈希查找
{
    int n,i=1;
    Hash *p;
    n=item % 19;
    if(a[n].data==-1){
        printf("\n查找失败，没有该数据！\n");
    }
    else if(a[n].data==item){
        printf("\n为开头第一个元素，查找成功！\n");
        printf("%d ",a[n].data);
    }
    else if(a[n].data!=-1 && a[n].data!=item ){
        if(a[n].next==NULL){
            printf("\n查找失败，没有该数据！\n");
        }
        else{
            p=a[n].next;
            while(p!=NULL)
            {
                i++;
                if(p->data==item){
                    printf("\n为子节点，查找成功\n");
                    break;
                }
                p=p->next;
            }
            if(p==NULL){
                printf("\n查找失败，没有该数据！\n");
            }
        }
    }
    return i;
}

int Delete(Hash a[19],int item)             //删除
{
    int n,i=1;
    Hash *p, *parent=NULL, *p1=NULL;
    n=item % 19;
    if(a[n].data==-1){
        printf("\n没有该数据！\n");
    }
    else if(a[n].data==item){
        printf("\n根结点，删除成功！\n");
        a[n].data=-1;
    }
    else if(a[n].data!=-1 && a[n].data!=item ){
        if(a[n].next==NULL){
            printf("\n没有该数据！\n");
        }
        else{
            p=a[n].next;
            while(p!=NULL)
            {
                i++;
                if(p->data==item){
                    printf("\n在表结点中，删除成功\n");
                    if(parent==NULL){
                        a[n].data=-1;
                    }
                    break;
                }
                parent=p;
                p=p->next;
            }
            if(p==NULL){
                printf("\n没有该数据！\n");
            }
        }
    }
    return i;
}


int main()
{
    int i, A[50];
    Hash d[19],*p;
    for(i=0;i<19;i++){              //哈希表的初始化
        d[i].data=-1;
        d[i].next=NULL;
    }
    printf("随机生成的数据为：\n");
    for(i = 0; i < 50; ++i){
		A[i]=rand()%800+200; 
        add_data(d,A[i]);
        printf("%d ",A[i]);
        if(i%10==9) printf("\n");
    }
    printf("\n请输入需要查找的关键字：");
    scanf("%d",&i);
    i=search(d,i);
    printf("共操作%d次\n",i);
    printf("\n请输入要删除的关键字：");
    scanf("%d",&i);
    i=Delete(d,i);
    printf("共操作%d次\n",i);
    return 0;
}
