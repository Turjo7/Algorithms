#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<queue>

using namespace std ;
#define MAX 100

#define WHITE 0
#define GREY 1
#define BLACK 2
#define EDGE 1

int i , j , m , n ;

int M , N ;

deque Q ;

deque :: iterator p ;

    int graph[MAX ][MAX ];
    int color[MAX ];
    int dist[MAX];
    int finish[MAX];

    int parent[MAX ] ;

void printPath(int start , int end )
{
     if( start == end )
         printf("%d ",start);

          else if( parent[ end ] == -1 )
                printf("No path from %d to %d\n",start,end);

 else
 {
        printPath( start , parent[end ] );

                printf("-> %d ",end );
 }
}

void Bfs( int s )
{
 int u ;

      for(i = 1 ; i <= N ; i++)
 {
      color[ i ] = WHITE ;

      dist[i ]   = -1 ;
      parent[ i] = -1 ;
 }
      color[ s ] = GREY ;

      dist[s ] = 0 ;

      parent[s ] = -1 ;

 Q.push_back(s) ;

 while( !Q.empty() )
 {
    u = Q.front();

    Q.pop_front();

    for( i=1 ; i<= N; i++)
    {
  if( color[i ] == WHITE && graph[u][i] == 1 )
  {
   color[i ] = GREY ;

     dist[i ] = dist[u] + 1 ;

   parent[ i] = u ;

   Q.push_back( i );
  }
    }
    color[u ] = BLACK ;
 }
}








int main()
{
// freopen("t.in","r",stdin);
// freopen("t.out","w",stdout);

 int a, b ;

 scanf("%d",&N);

while( 1 )
 {
  scanf("%d %d",&a,&b);

  if( a== 0 && b==0 )
   break ;

  graph[a][b] = 1 ;
 }
 while( scanf("%d",&a) != EOF )
 {
  scanf("%d",&b);
           Bfs(a);

  printf(" Source: %d , Destination: %d\t",a,b);

  printPath(a,b);

  printf(" End of Path\n\n");
 }
 return 0 ;
}

