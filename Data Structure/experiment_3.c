#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int shellsort(int a[], int n, int d[], int numofd)              //希尔排序
{
    int i, j, k, m, span, temp, num=0;
    for(i=0; i<numofd; i++){                //一共有numofd次循环
        span=d[i];
        for(k=0; k<span; k++){              //共有span个小组（小组成员分隔开）
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

int quicksort(int a[], int high, int low)           //快速排序算法
{
    int i=high, j=low;
    int temp=a[i], n=0;
    while(i<j)
    {
        while(i<j && temp<j) 
        {
            j--;
            n++;
        }
        if(i<j){
            a[i]=a[j];
            i++;
            n++;
        }
        while(i<j && temp>i) 
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
    if(low<i) n=n+quicksort(a,i-1,low);
    if(high>j) n=n+quicksort(a,high,j+1);
    return n;
}

int creatheap(int a[], int n, int h)            //最大堆化
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

int Initcreatheap(int a[], int n)               //初始化最大堆
{
    int i,num=0;
    for(i= (n-2)/2; i>=0; i--)
    {
        num=num+creatheap(a,n,i);
    }
    return num;
}

int heapsort(int a[],int n)                //堆查找
{
    int num=1,i,temp;
    Initcreatheap(a,n);
    for(i=n-1;i>0;i--){
        num++;
        temp=a[i];
        a[i]=a[0];
        a[0]=temp;
        creatheap(a, i, 0);                 //从上往下依次查找左右子树
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
    printf("希尔排序共操作%d次\n",num);
    for(i = 0; i < 50; ++i){
		A[i]=rand()%9800+200; 
    }
    num=quicksort(A,49,0);
    printf("快速排序共操作%d次\n",num);
     for(i = 0; i < 50; ++i){
		A[i]=rand()%9800+200; 
    }
    num=heapsort(A,49);
    printf("堆排序共操作%d次\n",num);
    return 0;
}


