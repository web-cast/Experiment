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
            q=(Hash *)malloc(sizeof(Hash));
            q->next=NULL;
            q->data=item;
            p->next=q;
        }
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
    else if(a[n].data=item){
        printf("\n查找成功！\n");
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
                if(p->data=item){
                    printf("\n查找成功\n");
                    break;
                }
                p=p->next;
            }
            if(p->data!=item){
                printf("\n查找失败，没有该数据！\n");
            }
        }
    }
    return i;
}

int delete(Hash a[19],int item)             //删除
{
    int n,i=1;
    Hash *p, *parent=NULL, *p1=NULL;
    n=item % 19;
    if(a[n].data==-1){
        printf("\n没有该数据！\n");
    }
    else if(a[n].data=item){
        printf("\n查找成功！\n");
        if(a[n].next==NULL){
            a[n].data=-1;
        }
        else{
            p=a[n].next;
            a[n].data=p->next->data;
            while(p->next!=NULL)
            {
                p->data=p->next->data;
                p1=p;
                p=p->next;
            }
            free(p);
            if(p1==NULL){
                a[n].next=NULL;
            }
            else{
                p1->next=NULL;
            }
        }
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
                if(p->data=item){
                    printf("\n查找成功\n");
                    if(parent==NULL){
                        a[n].next=p->next;
                    }
                    else{
                        parent->next=p->next;
                    }
                    break;
                }
                parent=p;
                p=p->next;
            }
            if(p->data!=item){
                printf("\n没有该数据！\n");
            }
        }
    }
    return i;
}


int main()
{
    srand((unsigned)time(NULL));
    int i, A[50];
    Hash d[19];
    for(i=0;i<19;i++){              //哈希表的初始化
        d[i].data=-1;
        d[i].next=NULL;
    }
    for(i = 0; i < 50; ++i){
		A[i]=(int) (round(1.0 * rand() / RAND_MAX * 800 + 200));
        add_data(d,A[i]);
    }
    printf("请输入需要查找的关键字：");
    scanf("%d",&i);
    i=search(A,i);
    printf("共操作%d次\n",i);
    printf("\n请输入要删除的关键字：");
    scanf("%d",&i);
    i=delete(A,i);
    printf("共操作%d次\n",i);
    return 0;
}
