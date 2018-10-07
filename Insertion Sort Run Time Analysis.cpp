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
	int i,j,t;
	srand(time(NULL));
	for(int i=0;i<=SZ;i++)
	{
		data[i]=rand()%MAX;
	}
	clock_t startTime=clock();
	 for(int j=1;j<=SZ-1;j++){
        t=data[j];
        i=j-1;
        while((i>=0)&&(data[i]>t)){
            data[i+1]=data[i];
            i=i-1;
        }
        data[i+1]=t;
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
