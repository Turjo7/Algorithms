#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<limits.h>

using namespace std;

int s[]={},c[]={};

int mcc(int n);
int printcoins(int n,int s[]);

int main()
{
    int n;
    printf("Enter The Amount Of Change\n");
    scanf("%d",&n);
    mcc(n);
    return 0;
}
int mcc(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        c[i]=-1;
    }
    if(c[n]==-1)
    {
        if(n==0)
        {
            c[n]=0;
            s[n]=0;
        }
        else
        {
            c[n]=INT_MAX;
            if(n>=50)
            {
                int temp=1+mcc(n-50);
                if(temp<c[n])
                {
                    c[n]=temp;
                    s[n]=50;
                }
            }
        }
        if(n>=25)
            {
                int temp=1+mcc(n-25);
                if(temp<c[n])
                {
                    c[n]=temp;
                    s[n]=25;
                }
    }
    if(n>=10)
            {
                int temp=1+mcc(n-10);
                if(temp<c[n])
                {
                    c[n]=temp;
                    s[n]=10;
                }
        }
        if(n>=1)
            {
                int temp=1+mcc(n-1);
                if(temp<c[n])
                {
                    c[n]=temp;
                    s[n]=1;
                }
       }
    }
    printcoins(n,s);



}
int printcoins(int n,int s[])
{
    if(s[n]!=0)
    {
        printf("%d",s[n]);
        printcoins(n-s[n],s);
    }
    return 0;
}

