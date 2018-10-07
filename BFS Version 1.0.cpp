#include<stdio.h>
#define N 10

int Q[N];
int f=-1,r=-1;
int qinsert(int d)
{
    if(r==N-1)
        printf("\nQueue is full!");
    else
    {
        if(f==-1)
            f=0;
        Q[++r]=d;
    }
    return 0;
}

int qdelete()
{
    if(f>r)
        printf("\nQueue is empty!");
    else
        return(Q[f++]);
    return 0;
}
int main()
{
    int a[25][25], status[50];
    int n, i, j, v, vstart;
    printf("\nHow Many Vertex In The Graph: ");
    scanf("%d",&n);
    printf("\nEnter adjacency matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    }
    printf("\nEnter starting vertex: ");
    scanf("%d",&vstart);
    for(i=1;i<=n;i++)
        status[i]=0;
    status[vstart]=1;
    qinsert(vstart);
    do
    {
        v=qdelete();
        for(i=0;i<=n;i++)
        {
            if(a[v][i]==1 && status[i]==0)
            {
                printf("%d",v);
                status[i]=1;
                qinsert(i);
            }
        }
        status[v]=2;
    }while(f!=r);

    return 0;
}
