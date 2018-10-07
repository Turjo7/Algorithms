#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <climits>
#define N 20

using namespace std;

void printArr(int arr[]){
     for(int i=0;i<20;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
}

void margeSort(int arr[],int l,int m1,int m2,int r){
    int i,j,p,k;
    int size1=m1-l+1;
    int size2=m2-m1;
    int size3=r-m2;
    int left[size1+1],mid[size2+1],right[size3+1];

    for(i=0;i<size1;i++){
        left[i]=arr[l+i];
    }
    for(j=0;j<size2;j++){
        mid[j]=arr[m1+j+1];
    }
    for(p=0;p<size3;p++){
        right[p]=arr[m2+p+1];
    }

    left[i]=LONG_MAX;
    mid[j]=LONG_MAX;
    right[p]=LONG_MAX;

    i = 0;
    j = 0;
    p = 0;
    k = l;

    while(k<=r){
        if(left[i]<=mid[j] && left[i]<=right[p]){
            arr[k]=left[i];
            i++;
            k++;
        }
        else if(right[p]<=mid[j]){
            arr[k]=right[p];
            p++;
            k++;
        }
        else{
            arr[k]=mid[j];
            j++;
            k++;
        }
    }
}

void divide(int arr[],int l,int r){
    int m1,m2,div;

    if(l<r){
        div=(r-l+1)/3;
        m1 = l+div;
        m2 = m1+div;
        divide(arr,l,m1);
        divide(arr,m1+1,m2);
        divide(arr,m2+1,r);
        margeSort(arr,l,m1,m2,r);
    }

}


int main(){
    int arr[N];
    int a,b,c;

    for(int i=0;i<N;i++){
        arr[i]=rand()%(2*N);
    }

    cout<<"The Array : - "<<endl<<endl;

    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }

    divide(arr,0,N-1);    //N-1 is the last index

    cout<<endl<<endl;
    cout<<"The Sorted Array : - "<<endl<<endl;

    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl<<endl<<endl;
    return 0;
}
