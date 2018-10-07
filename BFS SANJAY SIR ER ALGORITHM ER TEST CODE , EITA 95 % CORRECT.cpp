#include<stdio.h>
#include<iostream>
#include<limits.h>

#define N 100
#define M 10
#define WHITE 1
#define GRAY 2
#define BLACK 0
#define NIL -1


int Graph[M][M];
int Q[N];
int color[N];
int d[N];
int pi[N];
int f=-1,r=-1;


int vertices, edges;
int u, v;
int i, j;

void InputGraph(){
    printf("Enter The Number Of Vertex and Edges:\n");
    scanf("%d%d", &vertices, &edges);

    for(i = 0; i < vertices; ++i)
        for(j = 0; j < vertices; ++j)
            Graph[i][j] = 0;


    printf("Enter (u v):\n");
    for(i = 0; i < edges; ++i){
        scanf("%d%d", &u, &v);

        Graph[u][v] = Graph[v][u] = 1;
    }
}

void PrintGraph(){

    printf("\n");
    printf("Graph:\n");
    for(i = 0; i < vertices; ++i){
        for(j = 0; j < vertices; ++j)
            printf("%d ", Graph[i][j]);
        printf("\n");
    }
    printf("\n");
}
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
void BFS(int start)
{
    for(int i=1;i<=vertices;i++)
    {
        color[i]=WHITE;
        d[i]=INT_MAX;
        pi[i]=NIL;
    }
    color[start]=GRAY;
    d[start]=0;
    pi[start]=NIL;
    qinsert(start);
    while(f!=r)
    {
        int u=qdelete();
        for(int i=0;i<=vertices;i++)
        {
            if(color[i]==WHITE)
            {
                printf("%d\t",u);
                color[i]=GRAY;
                d[i]=d[u]+1;
                pi[i]=u;
                qinsert(i);
            }
        }
        color[u]=BLACK;
    }
    printf("Everything Of The Graph\n");
    printf("Color || Distance || Parent\n");
    for(int i=0;i<vertices;i++)
    {

        printf("\n%d\t%d\t%d\n",color[i],d[i],pi[i]);
    }




}

int main(){

    int s;
    printf("Input Your Graph:\n");



    InputGraph();
    PrintGraph();
    printf("Enter Starting Vertex\n");
    scanf("%d",&s);
    BFS(s);

    return 0;
}


