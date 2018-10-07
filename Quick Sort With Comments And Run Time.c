#include<stdio.h>
#include<time.h>
void quicksort(int a[100],int front,int rear){
    int p,j,temp,i;

     if(front<rear){
         p=front;
         i=front;
         j=rear;

         while(i<j){
             while(a[i]<=a[p]&&i<rear)
                 i++;
             while(a[j]>a[p])                    // first partitaion element khuje ber korchi
                 j--;
             if(i<j){
                 temp=a[i];
                  a[i]=a[j];
                  a[j]=temp;
             }
         }                             // 1st partition element pawar ag e i or j cross na kora prjnt o swap korchi

         temp=a[p];    // i , j ke cross kor e gele tokhn prothm value er sath swap kora
         a[p]=a[j];
         a[j]=temp;
         quicksort(a,front,j-1);       // array er prothom ordek ke abaro partition ber korte call kora
         quicksort(a,j+1,rear);       // array er baki  ordek ke abaro partition ber korte call kora

    }
}



int main(){
  int a[100],size,i;
  clock_t endTime,startTime;  // run time janar jonoo variable declare korlm


  printf("Enter size of the array: ");
  scanf("%d",&size);

  printf("Enter %d elements: ",size);
  for(i=0;i<size;i++)
    scanf("%d",&a[i]);
    startTime=clock();     // runtime er jonoo clock start

  quicksort(a,0,size-1);   //quick sort function call kora
    endTime=clock();            // runtime stop korlm
  printf("Sorted elements: ");
  for(i=0;i<size;i++)
    printf(" %d",a[i]);
    printf("\n\tRun Time : %lf\n\n\n\n",(double)(endTime-startTime)/CLOCKS_PER_SEC);   // runtime koto seita print krlm

  return 0;
}


