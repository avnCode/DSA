#include<stdio.h>
#include<stdlib.h>


int *arr, size;

int insert(int *arr,int p, int x)
{
    int i=size;
    arr=(int*)realloc(arr, (sizeof(int) * (i+1)) );
    size=i+1;

    while (i>=p)
    {
        arr[i--]=arr[i-1];  
    }
    arr[i]=x; 
}


int reterive(int *arr,int p)
{
    return arr[p];
}

int del(int *arr,int p)
{
    int i=size;
    while(p<size)
    {
        arr[p-1]=arr[p];
        p++;
    }
    size=size-1;
}

int unique1(int *arr)
{   
    int curr=0;
    while(curr<size)
    {
        int check=curr+1;
        while(check<size)
        {   
            if (reterive(arr,curr)==reterive(arr,check))
               { 
                del(arr,check+1);
                check--;
               }
            check++;
        }
        curr++;
    }
}
