#include<stdio.h>
#include<stdlib.h>

struct node{
    int id;
    struct node *next;
};

struct graphNode{
    int v, e;
    struct node *adjList;
};

struct graphNode *myGraph(){
    int x, y;
    struct graphNode *g = (struct graphNode *)malloc(sizeof(struct graphNode));
    struct node *newNode, *temp;
    printf("Enter the number of vertex and edges respectively : ");
    scanf("%d %d", &g->v, &g->e);
    g->adjList = (struct node *)malloc(g->v * (sizeof(struct node)));
    for(int i=0; i<g->v; i++){
        g->adjList[i].id = i;
        g->adjList[i].next = g->adjList + i;
    }
    for(int j=0; j<g->e; j++){
        printf("Enter the id's that the edge connect :");
        scanf("%d %d", &x, &y);
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->id = y;
        newNode->next = (g->adjList + x);
        temp = (g->adjList + x);
        while(temp->next != (g->adjList + x))
            temp = temp->next;
        temp->next = newNode;
    }
    return g;
}

int main(){
    myGraph();
    return 0;
}