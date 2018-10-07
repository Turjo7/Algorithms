#include <iostream>
#include <queue>
#include <limits.h>

using namespace std;

#define MAX_VERTICES 100
#define WHITE 1
#define GRAY 2
#define BLACK 0
#define NIL -1

int Adj[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];
int dist[MAX_VERTICES];
int parent[MAX_VERTICES];
int nE, nV;
int s;

void inputGraph() {
	
	int u, v;
	
	cout << "Enter number of nodes: ";
	cin >> nV;
	
	cout << "Enter number of edges: ";
	cin >> nE;
	
	cout << "Now enter the edges" << endl;

	for (int i=0; i < nE; i ++) {
		cin >> u >> v; // this means there is an edge: u <----> v
		
		Adj[u][v] = 1; // we can go from u to v
		Adj[v][u] = 1; // we can go from v to u
	}
	
	cout << endl << "Enter the source: ";
	cin >> s; // s = source
}
