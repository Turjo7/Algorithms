#include <stdio.h>

int maximum(int a, int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }

    return 0;
}



int knapsack(int W, int wt[], int val[], int n)
{
   int i, w;
   int T[n+1][W+1];


   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               T[i][w] = 0;
           else if (wt[i-1] <= w)
                 T[i][w] = maximum(val[i-1] + T[i-1][w-wt[i-1]],  T[i-1][w]);
           else
                 T[i][w] = T[i-1][w];
       }
   }

   return T[n][W];
}


int main()
{
    int val[] = {10, 40, 30,50};
    int wt[] = {5, 4, 6,3};
    int  W = 10;
    int n = 4;
    int result=knapsack(W, wt, val, n);
    printf("\The Maximum Profit Will Be  = %d Taka\n\n",result);
    return 0;
}

