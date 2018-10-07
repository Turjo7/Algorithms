#include<stdio.h>

int a[50];
void part(int a[],int min,int max);
void merge(int a[],int min,int mid,int max);

int main()
{
	int s,i;
	printf("How Many Numbers In Your Array\n");
	scanf("%d",&s);
	printf("Enter Your Array\n");
	for(i=0;i<s;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Your Inputed Array\n");
	for(i=0;i<s;i++)
	{
		printf("%d\t",a[i]);
	}
	part(a,0,s-1);
	printf("\nThe Array After Merge Sort\n");
	for(i=0;i<s;i++)
    {
        printf("%d\t",a[i]);
    }
	return 0;


}
void part(int a[],int min,int max)
{
	int mid;
	if(min<max)
	{
		mid=(min+max)/2;
		part(a,min,mid);
		part(a,mid+1,max);
		merge(a,min,mid,max);
	}
}
void merge(int a[],int min,int mid,int max)
{
	int i,j,k,m,t[50];
	j=min;
	m=mid+1;

	for(i=min;j<=mid&&m<=max;i++)
	{
		if(a[j]<=a[m])
		{
			t[i]=a[j];
			j++;
		}
		else
		{
			t[i]=a[m];
			m++;
		}

	}
	if(j>mid)
	{
		for(k=m;k<=max;k++)
		{
			t[i]=a[k];
			i++;
		}
	}
	else
	{
		for(k=j;k<=mid;k++)
		{
			t[i]=a[k];
			i++;
		}

	}
	for(i=min;i<=max;i++)
	{
		a[i]=t[i];
	}


}
