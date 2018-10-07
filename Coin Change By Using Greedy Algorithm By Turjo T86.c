#include<stdio.h>

int c[]={20,10,5,2,1};
int q[50];
int n=5;

int gcc(int amount,int c[],int n,int q[])
{
    int i=0;
    int num=0;
    while(amount>0)
    {
        q[i]=amount/c[i];
        amount=amount%c[i];
        num=num+q[i];
        i++;
    }
    return num;
}
int main()
{
    int amount,r;
    printf("Enter Amount\n");
    scanf("%d",&amount);
    r=gcc(amount,c,n,q);
    printf("You Will Need Total Number Of-> %d Coins\n",r);
    return 0;
}
