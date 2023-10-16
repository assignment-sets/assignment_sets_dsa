#include<stdio.h>
#include<stdlib.h>
#define q_size 50
#define data_size 6
#define numEdges 8

int queue[q_size], front = -1, rear = -1;
int dataSet[data_size] = {1, 5, 3, 4, 2, 7};
struct graph *g;

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

void enqueue(int data){
    if(rear == q_size-1){
        printf("Queue Overflow !");
        return;
    }
    if(front == -1){
        front = rear = 0;
        queue[front] = data;
    }
    rear++;
    queue[rear] = data;
}

int dequeue(){
    if(front == -1 || front > rear){
        front = rear = -1;
        printf("Queue Underflow !");
        return -1;
    }
    int temp = queue[front]; 
    front++;
    return temp;
}

int main(){
    g = myGraph(dataSet);
    return 0;
}