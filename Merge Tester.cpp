#include <iostream>
#include <ctime>
#include<cstdlib>
using namespace std;
void mergesort(int[], int, int);
void merge(int[], int, int, int);
void mergesort(int a[], int low, int high)
{
int mid;
if(low<high)
{
mid=(low+high)/2;
mergesort(a,low,mid);
mergesort(a,mid+1,high);
merge(a,low,high,mid);
}

}

void merge(int a[], int low, int high, int mid)
{
int i, j, k, c[50];
i=low;
j=mid+1;
k=low;
while((i<=mid)&&(j<=high))
{
if(a[i]<a[j])
{
c[k]=a[i];
k++;
i++;
}
else
{
c[k]=a[j];
k++;
j++;
}
}
while(i<=mid)
{
c[k]=a[i];
k++;
i++;
}
while(j<=high)
{
c[k]=a[j];
k++;
j++;
}
for(i=low;i<k;i++)
{
a[i]=c[i];
}
}

int main ()
{
	int randNum[100];
	clock_t sTime;


	cout << "Start generating random numbers..." << endl;
	for(int index=0; index<100; index++){
		randNum[index] = (rand()%1000)+1;
	}

	sTime = clock();
	mergesort(randNum, 0, 99);
    // delay the program by 0.05 second
    clock_t cWait = clock();

	cout << "Total CPU time used: " << (double) (clock()-sTime)/CLOCKS_PER_SEC \
    << " seconds" << endl;
}
