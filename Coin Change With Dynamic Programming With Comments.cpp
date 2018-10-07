#include<stdio.h>
int count( int S[], int m, int n )
{
                // n hoilo koto taka ferot dibo seita
    if (n == 0)   // jdi 0 taka return kori tahole kono change dit e hb e na
        return 1;

    // If n is less than 0 then no solution exists
    if (n < 0)     // jodi n er value hoy negative taile kono solutions thakbe na
        return 0;

    // If there are no coins and n is greater than 0, then no solution exist
    if (m <=0 && n >= 1) // jodi kono coin na thake tail e kono taka ferot dewa jabe na,
        return 0;


     return count( S, m - 1, n ) + count( S, m, n-S[m-1] );
     // recursion diye ber korte hb e koto taka ar ferot dit e hb e, ei
     // recursion er kaj hoilo ek ta stage prjnto recurison tree banano ar oi level prjnto sonkha ta koto sei mon e rakha
}


int main()
{
    int i, j,n;
    int arr[] = {1, 2, 3};  // ei array te ache kon coin gula use korbo, eita sort kora nite hb e choto theke boro
    int m = 3; // array te koto gula coin ache sei sonkha
    printf("Enter The Amount Of Change\n");
    scanf("%d",&n);
    printf("Total Coins Needed- %d ", count(arr, m, n));

    return 0;
}
