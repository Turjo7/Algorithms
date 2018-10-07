

#include <climits>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

struct krus{
	int u, v, w;
} edges[1000];

struct krus_complete{
	int u, v, w;
} final_edges[1000];

int e=0,final_e=0;;
int visited[1000];

int compare(krus a, krus b){
	return a.w<b.w;
}

void kruskal(int n) {

	int connection[1000];
	for(int i=0;i<n;i++){
		connection[i]=i;
		visited[i]=0;
	}

	sort(edges,edges+e,compare);
	for (int i = 0; i < e; i++){

		if(connection[edges[i].u]!=connection[edges[i].v] && visited[edges[i].v]!=1){
			final_edges[final_e].u=edges[i].u;
			final_edges[final_e].v=edges[i].v;
			final_edges[final_e].w=edges[i].w;
			final_e++;
			connection[edges[i].v]=connection[edges[i].u];
			visited[edges[i].u]=visited[edges[i].v]=1;
		}
	}

	for(int i=0;i<final_e;i++){
		cout << final_edges[i].u << " -> " << final_edges[i].v << " = " << final_edges[i].w << endl;
	}

}

int main(){
	int w,n;

	ifstream file("input1.txt");

	file >> n;
	e = 0;

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			file >> w;
			if (w != 0){
				edges[e].u = i;
				edges[e].v = j;
				edges[e].w = w;
				e++;
			}
		}
	}

	kruskal(n);

	return 0;
}
