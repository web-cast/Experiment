#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Hash{
    int data;
    struct Hash *next;
}Hash;

int add_data(Hash a[19], int item)          //��ϣ��Ľ���
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

int search(Hash a[19],int item)             //��ϣ����
{
    int n,i=1;
    Hash *p;
    n=item % 19;
    if(a[n].data==-1){
        printf("\n����ʧ�ܣ�û�и����ݣ�\n");
    }
    else if(a[n].data=item){
        printf("\n���ҳɹ���\n");
    }
    else if(a[n].data!=-1 && a[n].data!=item ){
        if(a[n].next==NULL){
            printf("\n����ʧ�ܣ�û�и����ݣ�\n");
        }
        else{
            p=a[n].next;
            while(p!=NULL)
            {
                i++;
                if(p->data=item){
                    printf("\n���ҳɹ�\n");
                    break;
                }
                p=p->next;
            }
            if(p->data!=item){
                printf("\n����ʧ�ܣ�û�и����ݣ�\n");
            }
        }
    }
    return i;
}

int delete(Hash a[19],int item)             //ɾ��
{
    int n,i=1;
    Hash *p, *parent=NULL, *p1=NULL;
    n=item % 19;
    if(a[n].data==-1){
        printf("\nû�и����ݣ�\n");
    }
    else if(a[n].data=item){
        printf("\n���ҳɹ���\n");
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
            printf("\nû�и����ݣ�\n");
        }
        else{
            p=a[n].next;
            while(p!=NULL)
            {
                i++;
                if(p->data=item){
                    printf("\n���ҳɹ�\n");
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
                printf("\nû�и����ݣ�\n");
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
    for(i=0;i<19;i++){              //��ϣ��ĳ�ʼ��
        d[i].data=-1;
        d[i].next=NULL;
    }
    for(i = 0; i < 50; ++i){
		A[i]=(int) (round(1.0 * rand() / RAND_MAX * 800 + 200));
        add_data(d,A[i]);
    }
    printf("��������Ҫ���ҵĹؼ��֣�");
    scanf("%d",&i);
    i=search(A,i);
    printf("������%d��\n",i);
    printf("\n������Ҫɾ���Ĺؼ��֣�");
    scanf("%d",&i);
    i=delete(A,i);
    printf("������%d��\n",i);
    return 0;
}
