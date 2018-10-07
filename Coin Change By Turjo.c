#include<stdio.h>

int cc(int amount);

int c[]={50,25,10,5,1};
int q[50];
int n=5;
int main()
{
	int amount,r,j;
	printf("Enter The Amount To Give Change\n");
	scanf("%d",&amount);
	r=cc(amount);
	printf("Total Number Of Coins Needed: %d \n",r);
	for(j=0;j<n;j++)
	{
		if(q[j]!=0){
		printf("\n%d Coin Used %d",c[j],q[j]);
		}
	}
	printf("\n");
	return 0;

}
int cc(int amount)
{
	int nc=0,i=0;
	while(amount>0)
	{
		q[i]=amount/c[i];
		nc=nc+q[i];
		amount=amount%c[i];
		i++;

	}


	return nc;

}
