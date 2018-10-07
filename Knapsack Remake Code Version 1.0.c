#include<stdio.h>

void knapsack(float capacity, int n, float weight[], float profit[])
{
	float x[20], totalprofit,y;
	int i,j;
	y=capacity;
	totalprofit=0;
	for(i=0;i < n;i++)
		x[i]=0.0;              // jkhn kono item nei nai tkhn pura ta 0
	for(i=0;i < n;i++)
	{
		if(weight[i] > y)            // jodi 1 item er weight knapsack er wight theke beshi hy tahole oitat knapsack er soman weight nibo
			break;
		else
		{
			x[i]=1.0;                    // item nicchi tai 1 , jehetu float tai 1.0
			totalprofit=totalprofit+profit[i];    // sob gula item er lav + krtesi
			y=y-weight[i];
		}
	}
	if(i < n)
		x[i]=y/weight[i];      // value per kg koto seita hisab hochhe
	totalprofit=totalprofit+(x[i]*profit[i]);
	printf("The Selected Items Are :-\n ");
	for(i=0;i < n;i++)
		if(x[i]==1.0)
			printf("\nProfit Is %f With Weight %f ", profit[i], weight[i]);
		else if(x[i] > 0.0)
			printf("\n%f part of Profit %f with weight %f", x[i], profit[i], weight[i]);
	printf("\nTotal Profit for %d Objects With Capacity %f = %f\n\n", n, capacity,totalprofit);
}
void main()
{
	float weight[20],profit[20],ratio[20], t1,t2,t3;
	int n;

	float capacity;

	int i,j;
	printf("How Many Items:  ");
	scanf("%d", &n);
	printf("\nEnter The Capacity Of Knapsack : ");
	scanf("%f", &capacity);
	for(i=0;i < n;i++)
	{
		printf("\nEnter %d(th) Number Items  Profit: ", (i+1));
		scanf("%f", &profit[i]);
		printf("Enter %d(th) Number Items   Weight: ", (i+1));
		scanf("%f", &weight[i]);
		ratio[i]=profit[i]/weight[i];
	}

	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
		{
			if(ratio[i] > ratio[j])
			{
				t1=ratio[i];                        // value per kg koto seta hisab hochhe
				ratio[i]=ratio[j];                 // 2 ta item er value per kg compare kora hoiteche
				ratio[j]=t1;
				t2=weight[i];
				weight[i]=weight[j];                // item newar por ar koto tuku jayga tahkbe seita check hochhe
				weight[j]=t2;
				t3=profit[i];
				profit[i]=profit[j];              // maximum profit check hob e

				profit[j]=t3;                // maximum profit store hochhe
			}
		}
	knapsack(capacity,n,weight,profit);



}
