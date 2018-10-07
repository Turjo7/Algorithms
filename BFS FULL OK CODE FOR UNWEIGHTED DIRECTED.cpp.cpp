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
    printf("Enter Vertex and Edges:\n");
    scanf("%d%d", &vertices, &edges);


    for(i = 0; i < vertices; ++i)
        for(j = 0; j < vertices; ++j)
            Graph[i][j] = 0;


    printf("Enter (u v):\n");
    for(i = 0; i < edges; ++i){
        scanf("%d%d", &u, &v);

        Graph[u][v] = 1;
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
int Empty_queue()
{
    if(f==-1||f>r)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void BFS(int start)
{
    int U;
    for(int i=0;i<vertices;i++)
	{
		color[i]=WHITE;
		d[i]=INT_MAX;
		pi[i]=NIL;


	}

	color[start]=GRAY;
	d[start]=0;
	qinsert(start);
	printf("The BFS Sequence Is : ->>\n");
	while(!Empty_queue())
    {
        int V=qdelete();
        printf("%d\t",V);
        color[V]=BLACK;
        for(int i=0;i<vertices;i++)
            if(Graph[V][i]==1&&color[i]==WHITE)
        {
            qinsert(i);
            color[i]=GRAY;
        }
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





