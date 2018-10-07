#include<iostream>
#include<stdio.h>


int findPlatform(double arr[], double dep[], int n);
int sort1(double b[],int n);

int main()
{
    double arr[50],dep[50];
    int r,n;
    printf("Enter How Many Train\n");
    scanf("%d",&n);
    printf("Enter Arrival Time & Departing Time\n\n");
    for(int i=0;i<n;i++)
    {
        printf("Enter Arrival Time Of Train : %d\n",i+1);
        scanf("%lf",&arr[i]);
        printf("Enter Departing Time Of Train : %d\n",i+1);
        scanf("%lf",&dep[i]);
    }
    r=findPlatform(arr,dep,n);
    printf("The Number Of Platform Needed : %d\n",r);
    return 0;

}
int findPlatform(double arr[], double dep[], int n)
{

   sort1(arr,n);
   sort1(dep,n);


   int plat_needed = 1, result = 1;
   int i = 1, j = 0;


   while (i < n && j < n)
   {

      if (arr[i] < dep[j])
      {
          plat_needed++;
          i++;
          if (plat_needed > result)
              result = plat_needed;
      }
      else
      {
          plat_needed--;
          j++;
      }
   }

   return result;
}
int sort1(double b[],int n)
{
    int i,j,t;
    for(j=1;j<=n-1;j++){
        t=b[j];
        i=j-1;
        while((i>=0)&&(b[i]>t)){
            b[i+1]=b[i];
            i=i-1;
        }
        b[i+1]=t;
    }
    return 0;
}
