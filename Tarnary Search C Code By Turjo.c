
#include<stdio.h>
#include<conio.h>
void  tsearch(int *a,int i,int j,int k);
int main() {
  int a[30],n,i,k,temp,j;
  printf("How Many Numbers\n");
  scanf("%d",&n);
  printf("Enter The Array In Ascending Order\n");
  for(i=0;i<n;i++)
      scanf("%d",&a[i]);



  printf("Enter A Number To Search\n");
  scanf("%d",&k);
  tsearch(a,0,n-1,k);

  getch();
}

void tsearch(int *a,int i,int j,int k) {
  int m1,m2;
  m1 = i + (j - i) * 1 / 3;
  m2 = i + (j - i) * 2 / 3;
  if(k==a[m1])
   {
    printf("\nFound at %d",m1);
    return;
   }
  else  if(k==a[m2])
   {
    printf("\nFound at %d",m2);
    return;
   }
  if(k<a[m1])
    return(tsearch(a,i,m1-1,k));
  if(k>a[m2])
    return(tsearch(a,m2+1,j,k));
  else
    return(tsearch(a,m1+1,m2-1,k));
}
