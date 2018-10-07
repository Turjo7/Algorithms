#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int weight[10],value[10],vpkg[10],index[10],n,W,vpkgc[10],profit[10];
int input();
int value_per_keg();
int sortvpkg(int vpkg[]);
int cvpkg();
int knapsack();
int main()
{
    input();
    return 0;
}

int input()
{
    int i;
    printf("Enter The Weight Of The Knapsack\n");
    scanf("%d",&W);
    printf("How Many Items\n");
    scanf("%d",&n);
    printf("Enter The Weight & Price Of The Items\n");
    for(i=0;i<n;i++)
    {
        printf("Enter The Weight Of  ITEM %d\n",i+1);
        scanf("%d",&weight[i]);
        printf("Enter The Price Of  ITEM %d\n",i+1);
        scanf("%d",&value[i]);
    }
    for(i=0;i<n;i++)
    {
        vpkg[i]=value[i]/weight[i];
    }
    cvpkg();
    sortvpkg(vpkg);
    return 0;
}
int cvpkg()
{
    int i;
    for(i=0;i<n;i++)
    {
        vpkgc[i]=vpkg[i];
    }
    return 0;
}
int sortvpkg(int vpkg[])
{
    int i,j,temp,k=0;
    for(i=0;i<n-1;i++)
    for(j=0;j<n-i-1;j++){
        if(vpkg[j]<vpkg[j+1]){
            temp=vpkg[j];
            vpkg[j]=vpkg[j+1];
            vpkg[j+1]=temp;

        }
    }


    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++){
            if(vpkg[i]==vpkgc[j])
        {
            index[k]=j;
            k++;

            }
         }
        }

    /*for(i=0;i<n;i++)
    {
        printf("%d\n\n",index[i]);
    }*/
    knapsack();


    return 0;
}
int knapsack()
{
    int i,sum=0,t,k,p=0;
    for(i=0;i<n;i++)
    {
        t=index[i];
        k=value[t];
    if(weight[t]<W)
    {
        printf("Item Number %d Is Taken\n",t+1);
        profit[p]=k;
        p++;

    }

    }
    for(i=0;i<n;i++)
    {
        sum=sum+profit[i];
    }
    printf("\nThe Maximum Profit Will Be: %d\n",sum);

    return 0;
}

