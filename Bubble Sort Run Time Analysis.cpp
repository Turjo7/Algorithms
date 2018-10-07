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
	int i,j,temp;
	srand(time(NULL));
	for(int i=0;i<=SZ;i++)
	{
		data[i]=rand()%MAX;
	}
	clock_t startTime=clock();
	 for(i=0;i<SZ-1;i++)
    for(j=0;j<SZ-i-1;j++){
        if(data[j]>data[j+1]){
            temp=data[j];
            data[j]=data[j+1];
            data[j+1]=temp;
        }
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

