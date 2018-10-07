#include<stdio.h>
#include<limits.h>
#include<time.h>
#include<stdlib.h>
#define size 5



using namespace std;
int heapsize=size;
int temp;

void PrintSolution(int array[])
{
    printf("\nElements after sorting: \n");
    for(int i=0; i<size; i++)
    {
        printf("%d ",array[i]);
    }
}

void MaxHeapify(int array[],int i)
{
    int Left=2*i;
    int Right=2*i+1;
    int largest;
    if(Left<heapsize && array[Left]>array[i])
    {
        largest=Left;
    }

    else
    {
        largest=i;
    }

    if(Right<heapsize && array[Right]>array[largest])
    {
        largest=Right;
    }

    if(largest!=i)
    {
        temp=array[largest];
        array[largest]=array[i];
        array[i]=temp;
        MaxHeapify(array,largest);
    }


}
void BuildMaxHeap(int array[])
{
    int i;
    for( i=heapsize/2; i>=0; i--)
    {
        MaxHeapify(array,i);
    }
    printf("HEAP TREE: ");
    for(i=0; i<heapsize; i++)
    {
        printf("%d ",array[i]);
    }
}
void HeapSort(int array[])
{
    BuildMaxHeap(array);
     while(heapsize>1)
    {
        temp=array[0];
        array[0]=array[heapsize-1];
        array[heapsize-1]=temp;
        heapsize--;
        MaxHeapify(array,0);
    }
}
int main()
{
    int array[size];
    srand(time(NULL));
    printf("Input:\n");
    for(int i=0; i<size; i++)
    {
        array[i]=rand()%size;
        printf("%d ",array[i]);
    }
    HeapSort(array);
    PrintSolution(array);
    return 0;
}
