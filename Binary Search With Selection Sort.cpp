#include<iostream>
#include<cstdlib>
#include<ctime>

#define SZ 10
#define max 100


using namespace std;
int bsearch(int data[],int low,int high,int key);
int main()
{
    int data[SZ],temp,i,j,key,flag,min;
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

     endTime=clock();
     diff=(double)(endTime-startTime)/CLOCKS_PER_SEC;
     cout<<"The Run Time Is "<<diff<<endl;
     for(int i=0;i<SZ;i++)
     {
         cout<<data[i]<<' ';
     }
     cout<<"\nEnter A Key To Search"<<endl;
     cin>>key;
    flag=bsearch(data,0,SZ-1,key);

    if(flag==-1){
        cout<<" Not Found "<<flag<<endl;
    }
    else{
        cout<<"Found At Index : "<<flag<<endl;
    }
     cout<<endl;
     return 0;

 }
}
int bsearch(int data[],int low,int high,int key)
{
    int mid;
    if(low>high){
        return -1;
    }
    mid=((low+high)/2);
    if(data[mid]==key){
        return mid;
    }
    else{
        if(data[mid]>key){
            return bsearch(data,low,mid-1,key);
        }
        else{
            return bsearch(data,mid+1,high,key);
        }
    }
    return 0;
}

