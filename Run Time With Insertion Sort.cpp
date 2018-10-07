#include<iostream>
#include<cstdlib>
#include<ctime>

#define SZ 10
#define max 100

using namespace std;
int main()
{
    int data[SZ],t,min,i,j;
    double diff;
    for(int i=0;i<SZ;i++)
    {
        data[i]=rand()%max;
    }
     clock_t endTime,startTime;
     startTime=clock();
     for(int j=1;j<=SZ-1;j++){
        t=data[j];
        i=j-1;
        while((i>=0)&&(data[i]>t)){
            data[i+1]=data[i];
            i=i-1;
        }
        data[i+1]=t;
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

