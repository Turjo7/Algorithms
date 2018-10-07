#include<stdio.h>

#include<conio.h>



void activities(int s[], int f[], int n)

{

	int i, j;

	printf ("Selected Activities are:\n");

	i = 1;

	printf("A%d ", i);

	for (j = 1; j < n; j++)

	{

		if (s[j] >= f[i])

		{

			printf ("A%d ", j+1);

			i = j;

		}

	}

}



int main()

{

	int s[] =  {2,7,4,6,8};

	int f[] =  {5,8,9,10,11};

	int n=5;




	activities(s, f, n);

	getchar();

	getch();
	return 0;


}
