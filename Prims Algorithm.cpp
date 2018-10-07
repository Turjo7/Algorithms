#include <stdio.h>
#include <limits.h>


#define V 5

int Graph[100][100];
int vertices,edges;
int u,v,w;



int minKey(int key[], bool mstSet[])
{

   int min = INT_MAX, min_index;

   for (int v = 0; v < V; v++)
     if (mstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;

   return min_index;
}

int printMST(int parent[], int n)
{
   printf("Edge   Weight\n");
   for (int i = 1; i < V; i++)
      printf("%d - %d    %d \n", parent[i], i, Graph[i][parent[i]]);
}



void primMST()
{
     int parent[V];
     int key[V];
     bool mstSet[V];


     for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;


     key[0] = 0;
     parent[0] = -1;


     for (int count = 0; count < V-1; count++)
     {

        int u = minKey(key, mstSet);


        mstSet[u] = true;


        for (int v = 0; v < V; v++)


          if (Graph[u][v] && mstSet[v] == false && Graph[u][v] <  key[v])
             parent[v]  = u, key[v] = Graph[u][v];
     }


     printMST(parent, V);
}



int main()
{
   printf("Enter Vertex and Edges:\n");
    scanf("%d%d", &vertices, &edges);


    for(int i = 0; i < vertices; i++)
        for(int j = 0; j < vertices; j++)
            Graph[i][j] = 0;


    printf("Enter (u v w):\n");
    for(int i = 0; i < edges; i++){
        scanf("%d%d%d", &u, &v, &w);

        Graph[u][v] = Graph[v][u] = w;
    }


    primMST();

    return 0;
}
