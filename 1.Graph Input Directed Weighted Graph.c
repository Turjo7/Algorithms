#include<stdio.h>

#define N 100


int Graph[N][N];


int vertices, edges;
int u, v, w;
int i, j;

void InputGraph(){
    printf("Enter vertices and Edges:\n");
    scanf("%d%d", &vertices, &edges);


    for(i = 0; i < vertices; ++i)
        for(j = 0; j < vertices; ++j)
            Graph[i][j] = 0;


    printf("Enter (u v w):\n");
    for(i = 0; i < edges; ++i){
        scanf("%d%d%d", &u, &v, &w);
        Graph[u][v] = w;
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

int main(){

    printf("Directed Weighted Graph:\n");


    InputGraph();
    PrintGraph();

    return 0;
}
