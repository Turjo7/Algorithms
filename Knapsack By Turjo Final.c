#include<stdio.h>
#include<stdlib.h>


void knapsack(int n,float weight[],float profit[],float capacity)
{
    float x[50],tp=0;
    int i,j,u;
    u=capacity;
    for(i=0;i<n;i++)
    {
        x[i]=0.0;
    }
    for(i=0;i<n;i++)
    {
        if(weight[i]>u)
        {
            break;
        }
        else{
            x[i]=1.0;
            tp=tp+profit[i];
            u=u-weight[i];
        }
    }
    if(i<n)
    {
        x[i]=u/weight[i];
        tp=tp+(x[i]*profit[i]);
    }
    printf("The Items Taken\n");
    for(i=0;i<n;i++)
    {
        printf("%f\t",x[i]);
    }
    printf("The Maximum Profit Is : %f\t",tp);

}

int main()
{
    float weight[50],profit[50],capacity,ratio[50],temp;
    int i,j,n;
    printf("How Many Items\n");
    scanf("%d",&n);
    printf("Enter The Weight And Profit Of The Items\n");
    for(i=0;i<n;i++)
    {
        printf("Enter The Weight Of Item Number: %d \n",i+1);
        scanf("%f",&weight[i]);
        printf("Enter The Value Of Item Number: %d \n",i+1);
        scanf("%f",&profit[i]);
    }
    printf("Enter The Capacity Of The Knapsack\n");
    scanf("%f",&capacity);
    for(i=0;i<n;i++)
    {
        ratio[i]=profit[i]/weight[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(ratio[i]<ratio[j])
            {
                temp=ratio[j];
                ratio[j]=ratio[i];
                ratio[i]=temp;
                temp=weight[j];
                weight[j]=weight[i];
                weight[i]=temp;
                temp=profit[j];
                profit[j]=profit[i];
                profit[i]=temp;
            }
        }
    }
    knapsack(n,weight,profit,capacity);
    return 0;

}
