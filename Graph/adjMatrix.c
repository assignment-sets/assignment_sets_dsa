// considering a undirected graph in this case

#include<stdio.h>
#include<stdlib.h>

struct graph{
    int v, e;
    int **adjMatrix;
};

struct graph *myGraph(){
    int u, v;
    struct graph *g = (struct graph *)malloc(sizeof(struct graph));
    printf("Enter the number of vertex and edges respectively : ");
    scanf("%d %d", &g->v, &g->e);
    g->adjMatrix = (int **)malloc(sizeof(int *) *g->v);
    for(int i=0 ; i<g->v; i++){
        g->adjMatrix[i] = (int *)malloc(sizeof(int) * g->v);
        for(int j=0; j<g->v; j++){
            g->adjMatrix[i][j] = 0;
        }
    }
    for(int i=0; i<g->e; i++){
        printf("Enter pair of indices of nodes that connects an edge : ");
        scanf("%d %d", &u, &v);
        g->adjMatrix[u][v] = 1;
        g->adjMatrix[v][u] = 1;
    }
    return g;
}

int main(){
    struct graph *result = myGraph();
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            printf("%d ", result->adjMatrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}