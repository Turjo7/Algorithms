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
    int minimum;
    if(Left<heapsize && array[Left]<array[i])
    {
        minimum=Left;
    }

    else
    {
        minimum=i;
    }

    if(Right<heapsize && array[Right]<array[minimum])
    {
        minimum=Right;
    }

    if(minimum!=i)
    {
        temp=array[minimum];
        array[minimum]=array[i];
        array[i]=temp;
        MaxHeapify(array,minimum);
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
        scanf("%d",&array[i]);

    }
    printf("Your Inputed Array\n");
    for(int i=0; i<size; i++)
    {

        printf("%d ",array[i]);
    }
    HeapSort(array);
    PrintSolution(array);
    return 0;
}

