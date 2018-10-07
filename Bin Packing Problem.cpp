#include <iostream>
using namespace std;


int nextFit(int weight[], int n, int c)
{

   int result = 0, bin_remain = c;


   for (int i=0; i<n; i++)
   {

       if (weight[i] > bin_remain)
       {
          result++;
          bin_remain = c - weight[i];
       }
       else
         bin_remain = bin_remain-weight[i];
   }
   return result;
}


int main()
{
    int weight[] = {2, 5, 4, 7, 1, 3, 8};
    int c = 10;
    int n =7;
    cout << "Total Bins Needed->>  : "
         << nextFit(weight, n, c);
    return 0;
}
