
#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<ctime>

#define SZ 10
#define MAX 100

using namespace std;
void part(int a[],int min,int max);
void merge(int a[],int min,int mid,int max);


int main()
{
	int data[SZ]={};
	int i,j,temp,min;
	//srand(time(NULL));


	for(int i=0;i<=SZ;i++)
	{
		data[i]=rand()%MAX;
	}

	part(data,0,SZ-1);






	/*for(int i=0;i<SZ;i++)
	{
		cout<<data[i]<<endl;
	}*/
	printf("Run Time : %lf",(double)(endTime-startTime)/CLOCKS_PER_SEC);
	cout<<endl;

	return 0;

}
void part(int data[],int min,int max)
{
	int mid;
	srand(time(NULL));
	if(min<max)
	{
		mid=(min+max)/2;
		part(data,min,mid);
		part(data,mid+1,max);
		clock_t startTime=clock();
		merge(data,min,mid,max);
		clock_t endTime=clock();
	}

}
void merge(int data[],int min,int mid,int max)
{
	int i,j,k,m,t[50];
	j=min;
	m=mid+1;



	for(i=min;j<=mid&&m<=max;i++)
	{
		if(data[j]<=data[m])
		{
			t[i]=data[j];
			j++;
		}
		else
		{
			t[i]=data[m];
			m++;
		}

	}
	if(j>mid)
	{
		for(k=m;k<=max;k++)
		{
			t[i]=data[k];
			i++;
		}
	}
	else
	{
		for(k=j;k<=mid;k++)
		{
			t[i]=data[k];
			i++;
		}

	}

	/*for(i=min;i<=max;i++)
	{
		data[i]=t[i];
	}*/

	printf("Run Time : %lf",(double)(endTime-startTime)/CLOCKS_PER_SEC);
	cout<<endl;




}


