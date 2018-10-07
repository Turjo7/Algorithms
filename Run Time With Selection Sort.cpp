#include<iostream>
#include<cstdlib>
#include<ctime>

#define SZ 10
#define max 100

using namespace std;
int main()
{
    int data[SZ],temp,min;
    double diff;
    for(int i=0;i<SZ;i++)
    {
        data[i]=rand()%max;
    }
     clock_t endTime,startTime;
     startTime=clock();
     for(int i=0;i<SZ;i++){
	  min=i;
	  for(int j=i+1;j<SZ;j++){
		if(data[min]>data[j])
			min=j;
	 }
	  temp=data[i];
	  data[i]=data[min];
	  data[min]=temp;

  }

     endTime=clock();
     diff=(double)(endTime-startTime)/CLOCKS_PER_SEC;
     cout<<"The Run Time Is "<<diff<<endl;
     for(int i=0;i<SZ;i++)
     {
         cout<<data[i]<<' ';
     }
     cout<<endl;
     return 0;

}
