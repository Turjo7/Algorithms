
#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<ctime>

#define SZ 300000
#define MAX 1000000

using namespace std;

int main()
{
	int data[SZ]={};
	int i,j,temp,min;
	srand(time(NULL));
	for(int i=0;i<=SZ;i++)
	{
		data[i]=rand()%MAX;
	}
	clock_t startTime=clock();
	for(i=0;i<SZ;i++){
		min=i;
		for(j=i+1;j<SZ;j++){
			if(data[min]>data[j]){
				min=j;
		}
	}
			temp=data[i];
			data[i]=data[min];
			data[min]=temp;


	}
	clock_t endTime=clock();


	for(int i=0;i<SZ;i++)
	{
		cout<<data[i]<<endl;
	}
	printf("Run Time : %lf",(double)(endTime-startTime)/CLOCKS_PER_SEC);
	cout<<endl;
	return 0;

}

