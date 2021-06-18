#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int shellsort(int a[], int n, int d[], int numofd)              //ϣ������
{
    int i, j, k, m, span, temp, num=0;
    for(i=0; i<numofd; i++){                //һ����numofd��ѭ��
        span=d[i];
        for(k=0; k<span; k++){              //����span��С�飨С���Ա�ָ�����
            for(m=k; m<n-span; m=m+span){
                temp=a[m+span];
                j=m;
                while(j>-1 && temp<a[j])
                {
                    a[j+span]=a[j];
                    j=j-span;
                    num++;
                }
                a[j+span]=temp;
            }
        }
    }
    return num;
}

int quicksort(int a[], int low, int high)           //���������㷨
{
    int i=high, j=low;
    int temp=a[i], n=0;
    printf("%d\n",1);
    while(i<j)
    {
        n+=5;
        while(i<j && temp<=a[j])            //���ұ߽��д���
        {
            j--;
            n++;
        }
        if(i<j){
            a[i]=a[j];
            i++;
            n++;
        }
        while(i<j && temp>a[i])             //����߽��д���
        {
            i++;
            n++;
        }
        if(i<j){
            a[j]=a[i];
            j--;
            n++;
        }
    }
    a[i]=temp;
    printf("%d\n%d\n%d\n%d",i,j,low,high);
    if(low<i) n=n+quicksort(a,low,i-1);
    if(high>j) n=n+quicksort(a,i+1,high);
    return n;
}

int creatheap(int a[], int n, int h)            //���ѻ�
{
    int i, j, flag, temp, num=0;
    i=h;
    j=2*h+1;
    temp=a[i];
    flag=0;
    while(j<n && flag!=1)
    {
        if(j<n-1 && a[j]<a[j+1]) j++;
        if(temp>a[j]) flag=1;
        else{
            a[i]=a[j];
            i=j;
            j=2*i+1;
        }
        num++;
    }
    a[i]=temp;
    return num;
}

int Initcreatheap(int a[], int n)               //��ʼ������
{
    int i,num=0;
    for(i= (n-2)/2; i>=0; i--)
    {
        num=num+creatheap(a,n,i);
    }
    return num;
}

int heapsort(int a[],int n)                //�Ѳ���
{
    int num=1,i,temp;
    Initcreatheap(a,n);
    for(i=n-1;i>0;i--){
        num++;
        temp=a[i];
        a[i]=a[0];
        a[0]=temp;
        creatheap(a, i, 0);                 //�����������β�����������
    }
    return num;
}

int main()
{
    int i, A[50],numofd=3,d[3]={6,3,1},num;
    for(i = 0; i < 50; ++i){
		A[i]=rand()%800+200; 
    }
    num=shellsort(A,50,d,numofd);
    printf("ϣ�����򹲲���%d��\n",num);
    for(i = 0; i < 50; ++i){
		A[i]=rand()%9800+200; 
    }
    num=quicksort(A,49,0);
    printf("�������򹲲���%d��\n",num);
     for(i = 0; i < 50; ++i){
		A[i]=rand()%9800+200; 
    }
    num=heapsort(A,49);
    printf("�����򹲲���%d��\n",num);
    return 0;
}


