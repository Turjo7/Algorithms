#include<stdio.h>
#include<iostream>
#include<limits.h>

#define N 100
#define M 10
#define WHITE 1  // white mane ekhono visit kora hoy nai
#define GRAY 2   // gray man e visit korar jono waiting e ache
#define BLACK 0   // black man e visit kora hoye geche
#define NIL -1       // nil man e kono parent nai


int Graph[M][M];            // graph input nib e
int Q[N];                  // adjacent node gula Queue te insert kora hobe
int color[N];                // kon vertex visit hoise seita track rakhbe
int d[N];                       // source theke distance rakhe d [] array
int pi[N];               // kon vertex er parent ke seita track rakhe pi [ ]
int f=-1,r=-1;                  // queue er front ar rear initialize kora hoise  f= -1 ar r = -1 dhore


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
int qinsert(int d)              // Queue te inset korar function rear diye insert kora hoise
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
int qdelete()      // Queue theke delete korar function, Front diye delete kora hoise
{
    if(f>r)
        printf("\nQueue is empty!");
    else
        return(Q[f++]);
    return 0;
}
int Empty_queue()           // queue empty kina seita check kora hoise
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

    for(int i=0;i<vertices;i++)   // prothom e sob gula vertex ke White , distance gula ke Infinity , parent gila ke NIL kora hoy
	{
		color[i]=WHITE;
		d[i]=INT_MAX;
		pi[i]=NIL;


	}

	color[start]=GRAY;       // source ke visit kora hb e first e , tai eta hb e gray
	d[start]=0;                // source theke source er distance always 0
	qinsert(start);            // source ke insert kora hochhhe queue te
	printf("The BFS Sequence Is : ->>\n");
	while(!Empty_queue())         // queue jotokhn prjnto na empty totokhn cholbe program
    {
        int V=qdelete();     // queue er shuru te jeta thakbe oita ke pop korbo
        printf("%d\t",V);
        color[V]=BLACK;     // pop kora tak e black banabo
        for(int i=0;i<vertices;i++)
            if(Graph[V][i]==1&&color[i]==WHITE)
        {

            color[i]=GRAY;               // source er sathe adjacent gula ke gray banabo
            d[i]=d[V]+1;            // oitar distance +1 kore dibo
            pi[i]=V;                     // jar kach theke ashtesi seta ke parent banabo
            qinsert(i);             // source er sathe je gula connected se gula ekta ekta kore queue te insert korbo
        }
    }
    printf("\n");
    for(int i=0;i<vertices;i++)
	{
		printf("Color [%d]\t Distance [%d]\t Parent [%d]\n\n",color[i],d[i],pi[i]);
	}


// finally pura array ta print kor e dib o
}

int main(){

    int s;
    printf("Input Your Graph:\n");



    InputGraph();
    PrintGraph();
    printf("Enter Starting Vertex\n");
    scanf("%d",&s);     // source konta sei ta input nibo
    BFS(s);

    return 0;
}






