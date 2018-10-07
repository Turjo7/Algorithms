
#include<stdio.h>
#include<algorithm>

using namespace std;

int arr[100];
int size;
void shiftDown(int a, int size){
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
		shiftDown(m, size);
	}
}

void heap(int size){

	for (int i = size / 2; i >= 1; i--){
		shiftDown(i, size);
	}

	while (size>1){
		int temp = arr[size];
		arr[size] = arr[1];
		arr[1] = temp;
		size--;
		shiftDown(1, size);
	}
}

void pop()
{
	printf("%d\n", arr[1]);
	swap(arr[1], arr[size]);
	size--;
	shiftDown(1, size);
	heap(size);
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
	heap(size);
}
void display()
{
	int i;
	for (i = 1; i <= size; i++)
	{
		printf("%d\t", arr[i]);
	}
}
void update()
{
    int new_value,n;
    printf("Enter The Value\n");
    scanf("%d",&new_value);
    printf("Enter The Index\n");
    scanf("%d",&n);
    if(new_value<arr[n])
    {
        arr[n]=new_value;
        shiftDown(n,size);
    }
    else
    {
        if(arr[n]<new_value)
        {
            int p=(n/2)-1;
            arr[n]=new_value;
            while(n>0&&arr[n]>arr[p])
            {
                swap(arr[n],arr[p]);
                n=p;
                int p=(n/2)-1;

            }
        }
    }
}
int main()
{
	int i, choice, k;
	printf("Priority Queue Code\n");
	printf("How Many Elements = \t");
	scanf("%d", &size);
	for (i = 1; i <= size; i++)
	{
		scanf("%d", &arr[i]);
	}
	heap(size);
	while(1)
	{
		printf("\nenter choice\n");
		printf("1. push\n");
		printf("2. pop\n");
		printf("3. display\n");
		printf("4. Update\n");
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
			case 4:
                update();
                break;
		}
	}
	return 0;
}


