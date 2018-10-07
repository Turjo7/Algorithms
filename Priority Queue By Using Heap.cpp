
#include<stdio.h>
#include<algorithm>

using namespace std;

int arr[100];
int size;
void heapify(int a, int size){
	int l = 2 * a;
	int r = 2 * a + 1;
	int m = a, max = arr[m];
	if (l <= size && max>arr[l]){
		max = arr[l];
		m = l;
	}
	if (r <= size && max>arr[r]){
		max = arr[r];
		m = r;
	}

	if (m != a){
		swap(arr[a], arr[m]);
		heapify(m, size);
	}
}

void makeheap(int size){

	for (int i = size / 2; i >= 1; i--){
		heapify(i, size);
	}

	while (size>1){
		int temp = arr[size];
		arr[size] = arr[1];
		arr[1] = temp;
		size--;
		heapify(1, size);
	}
}

void pop()
{
	printf("%d\n", arr[1]);
	swap(arr[1], arr[size]);
	size--;
	heapify(1, size);
	makeheap(size);
}
void push(int k)
{
	size++;
	int i = size;
	arr[i] = k;
	int p = (i / 2) + 1;
	while (p > 0 && arr[p] < arr[i])
	{
		swap(arr[p], arr[i]);
		i = p;
		p = (i / 2)+1;
	}
	makeheap(size);
}
void display()
{
	int i;
	for (i = 1; i <= size; i++)
	{
		printf("%d\t", arr[i]);
	}
}
int main()
{
	int i, choice, k;

	printf("How Many Elements You Want To Store\n");
	scanf("%d", &size);
	printf("Enter %d Elements\n",size);
	for (i = 1; i <= size; i++)
	{
		scanf("%d", &arr[i]);
	}
	makeheap(size);
	while(1)
	{
		printf("\nEnter Choice\n");
		printf("1. Push In Queue\n");
		printf("2. Pop From The Queue\n");
		printf("3. Show The Priority Queue\n");
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:
				printf("enter key:");
				scanf("%d", &k);
				push(k);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
		}
	}
	return 0;
}

