#include<iostream>
#include<cstdlib>
#include<ctime>

#define SZ 10
#define max 100
int bsearch(int a[],int start,int end,int key);

using namespace std;
int main()
{
    int a[SZ],t,min,i,j,key,flag;
    double diff;
    for(int i=0;i<SZ;i++)
    {
        a[i]=rand()%max;
    }
     clock_t endTime,startTime;
     startTime=clock();
     for(int j=1;j<=SZ-1;j++){
        t=a[j];
        i=j-1;
        while((i>=0)&&(a[i]>t)){
            a[i+1]=a[i];
            i=i-1;
        }
        a[i+1]=t;
    }

     endTime=clock();
     diff=(double)(endTime-startTime)/CLOCKS_PER_SEC;
     cout<<"The Run Time Is "<<diff<<endl;
     for(int i=0;i<SZ;i++)
     {
         cout<<a[i]<<' ';
     }
     cout<<"\nEnter A Key To Search"<<endl;
     cin>>key;
    flag=bsearch(a,0,SZ-1,key);

    if(flag==-1){
        cout<<" Not Found "<<flag<<endl;
    }
    else{
        cout<<"Found At Index : "<<flag<<endl;
    }
     cout<<endl;
     return 0;

}

int bsearch(int a[],int start,int end,int key)
{
    int i;
    if(start>end){
        return -1;
    }
    i=((start+end)/2);
    if(a[i]==key){
        return i;
    }
    else{
        if(a[i]>key){
            return bsearch(a,start,i-1,key);
        }
        else{
            return bsearch(a,i+1,end,key);
        }
    }
    return 0;
}
