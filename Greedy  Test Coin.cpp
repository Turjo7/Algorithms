#include<stdio.h>
#include<iostream>

int coin[]={10,20,5,2,1};

int change(int amount);

int main()
{
    int amount;
    printf("Enter The Amount To Be Given As Change To The Customer\n");
    scanf("%d",&amount);
    change(amount);
    return 0;
}
int change(int amount)
{
    int res=0;
    int i=0;
    while(amount>0)
    {
        if(amount<=coin[i])
        {
            amount=amount-coin[i];
            res++;
        }
        else{
            if(i==5)
            {
                res=res-1;
                break;
            }
            else{
                i++;
            }
        }
    }
    printf("%d\n",res);
    return 0;
}
