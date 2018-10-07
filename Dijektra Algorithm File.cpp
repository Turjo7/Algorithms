#include <stdio.h>

#define GRAPHSIZE 2048
#define INFINITY GRAPHSIZE*GRAPHSIZE
#define MAX(a, b) ((a > b) ? (a) : (b))

int e; /* The number of nonzero edges in the graph */
int n; /* The number of nodes in the graph */
long dist[GRAPHSIZE][GRAPHSIZE]; /* dist[i][j] is the distance between node i and j; or 0 if there is no direct connection */
long d[GRAPHSIZE]; /* d[i] is the length of the shortest path between the source (s) and node i */

void printD() {
    int i;
    for (i = 1; i <= n; ++i)
        printf("%10d", i);
    printf("\n");
    for (i = 1; i <= n; ++i) {
        printf("%10ld", d&#91;i&#93;);
    }
    printf("\n");
}

void dijkstra(int s) {
    int i, k, mini;
    int visited&#91;GRAPHSIZE&#93;;

    for (i = 1; i <= n; ++i) {
        d&#91;i&#93; = INFINITY;
        visited&#91;i&#93; = 0; /* the i-th element has not yet been visited */
    }

    d&#91;s&#93; = 0;

    for (k = 1; k <= n; ++k) {
        mini = -1;
        for (i = 1; i <= n; ++i)
            if (!visited&#91;i&#93; && ((mini == -1) || (d&#91;i&#93; < d&#91;mini&#93;)))
                mini = i;

        visited&#91;mini&#93; = 1;

        for (i = 1; i <= n; ++i)
            if (dist&#91;mini&#93;&#91;i&#93;)
                if (d&#91;mini&#93; + dist&#91;mini&#93;&#91;i&#93; < d&#91;i&#93;)
                    d&#91;i&#93; = d&#91;mini&#93; + dist&#91;mini&#93;&#91;i&#93;;
    }
}

int main(int argc, char *argv&#91;&#93;) {
    int i, j;
    int u, v, w;

    FILE *fin = fopen("dist.txt", "r");
    fscanf(fin, "%d", &e);
    for (i = 0; i < e; ++i)
        for (j = 0; j < e; ++j)
            dist&#91;i&#93;&#91;j&#93; = 0;
    n = -1;
    for (i = 0; i < e; ++i) {
        fscanf(fin, "%d%d%d", &u, &v, &w);
        dist&#91;u&#93;&#91;v&#93; = w;
        n = MAX(u, MAX(v, n));
    }
    fclose(fin);

    dijkstra(1);

    printD();

    return 0;
}
