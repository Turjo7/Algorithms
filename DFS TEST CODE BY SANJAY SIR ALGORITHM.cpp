#include <stdio.h>
#include <stdlib.h>

int source,V,E,time,visited[20],Graph[20][20];
void DFS(int i)
{
    int j;
    visited[i]=1;  // jei vertex visit korsi seita 1 banay dibo
    printf(" %d->",i+1);
    for(j=0;j<V;j++)
    {
        if(Graph[i][j]==1&&visited[j]==0)
            DFS(j);  // jei vertex gula source er sathe adjacent kintu visit hoy nai ekta ekta kore stack e insert korbo
    }
}
int main()
{
    int i,j,v1,v2;


    printf("How Many Vertex In The Graph\n");
    scanf("%d",&V);
    printf("How Many Edges In The Graph\n");
    scanf("%d",&E);
    for(i=0;i<V;i++)   // graph input nibo
    {
        for(j=0;j<V;j++)
            Graph[i][j]=0;
    }

    for(i=0;i<E;i++)
    {
        printf("Enter the edges (u,v)\n");
        scanf("%d%d",&v1,&v2);
        Graph[v1-1][v2-1]=1;

    }

    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
            printf(" %d ",Graph[i][j]);
        printf("\n");
    }
    printf("Enter The Source Vertex\n");
    scanf("%d",&source);   //source input niye nibo
        DFS(source-1);    // indexing er jonoo  1 minus kore recurssion call dibo
    return 0;
}
