#include<stdio.h>
int fib(int n)
{
   if (n <= 1)  // jodi negative pod or 1 er theke choto hoy taile jei sonkha input dey tahole code seita return korbe
      return n;
   return fib(n-1) + fib(n-2); // ar positive number input dil e prthme first 2 ta pod toiri hb e ,erpor oi ta jog kor e memory te rakhbe
                               // than oita ke next pod dhore aro ekta banabe seitar sathe ager ta jog korbe
}

int main ()
{
  int n;
  printf("Enter The Term Of Your Fibonochi Series\n");
  scanf("%d",&n); // koto pod prjnto fibonochi series er jog fol chai seita input nichhi
  printf("Sum Of The First %d Terms Of Fibonochi Series %d",n, fib(n)); // ei khane function ta call hochhe

  return 0;
}
//recursion tree jokhn n=9 ,series ta hb e 0, 1, 1, 2, 3, 5, 8, 13, 21

/**             fib(5)
                     /             \
               fib(4)                fib(3)
             /      \                /     \
         fib(3)      fib(2)         fib(2)    fib(1)
        /     \        /    \       /    \
  fib(2)   fib(1)  fib(1) fib(0) fib(1) fib(0)
  /    \
fib(1) fib(0)  **/
