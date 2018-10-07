#include<stdio.h>
#include<stdlib.h>

void quickSort( int a[], int beg, int end);
int partition( int a[], int beg, int end);

void main()
{
	int a[50],i,n;


	printf("How Many Elements In Your Array To Sort\n");
	scanf("%d",&n);

	for(i=0;i<n;i++)
    {
        a[i]=rand()%100+1;
    }
    printf("The Array\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }


	quickSort( a, 0, n-1);

	printf("\The Array After Sorting\n");
	for(i = 0; i < n; i++){
		printf("%d\n", a[i]);
	}

}
void quickSort( int a[], int beg, int end)
{
   int j;

   if( beg < end )
   {

       j = partition( a, beg, end);
       quickSort( a, beg, j-1);
       quickSort( a, j+1, end);
   }

}
int partition( int a[], int beg, int end) {
   int pivot, i, j, t;
   pivot = a[beg];
   i = beg; j = end+1;

   while( 1)
   {
   	do ++i; while( a[i] <= pivot && i <= end );
   	do --j; while( a[j] > pivot );
   	if( i >= j )
        break;
   	t = a[i]; a[i] = a[j]; a[j] = t;
   }
   t = a[beg]; a[beg] = a[j]; a[j] = t;
   return j;
}


