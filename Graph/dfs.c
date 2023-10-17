#include<stdio.h>
#include<stdlib.h>
#define data_size 6
#define numEdges 8

int dataSet[data_size] = {1, 5, 3, 4, 2, 7};
struct graph *g;
int visited[data_size] = {0};
int DFS_result[data_size], res_indx = 0;

struct node{
    int index, data;
    struct node *next;
};

struct graph{
    int v, e;
    struct node *adjList;
};

struct graph *myGraph(int *dataSet){
    int x, y;
    struct graph *g = (struct graph *)malloc(sizeof(struct graph));
    g->v = data_size;
    g->e = numEdges;
    g->adjList = (struct node *)malloc(sizeof(struct node)*g->v);
    for(int i=0; i<g->v; i++){
        g->adjList[i].index = i;
        g->adjList[i].data = dataSet[i];
        g->adjList[i].next = g->adjList + i;
    }
    for(int i=0; i<g->e; i++){
        printf("Enter the index of two vertex that a edge connects : ");
        scanf("%d %d", &x, &y);
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->index = y;
        newNode->data = g->adjList[y].data;
        newNode->next = g->adjList + x;
        struct node *temp = g->adjList + x;
        while(temp->next != g->adjList + x)
            temp = temp->next;
        temp->next = newNode;
    }
    return g;
}

void DFS(int src){
    visited[src] = 1;
    DFS_result[res_indx++] = g->adjList[src].data;
    struct node *temp = (g->adjList + src);
    while(temp->next != (g->adjList + src)){
        temp = temp->next;
        if(visited[temp->index] != 1)
            DFS(temp->index);
    }
}

int main(){
    int src;
    g = myGraph(dataSet);
    printf("Enter the src node index : ");
    scanf("%d", &src);
    DFS(src);
    printf("The dfs traversal result is :\n");
    for(int i=0; i<(data_size - src); i++)
        printf("%d ", DFS_result[i]);
    return 0;
}