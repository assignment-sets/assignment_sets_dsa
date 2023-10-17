#include<stdio.h>
#include<stdlib.h>
#define q_size 50
#define data_size 6
#define numEdges 8

int front = -1, rear = -1;
struct node *queue[q_size];
int dataSet[data_size] = {1, 5, 3, 4, 2, 7};
struct graph *g;
int visited[data_size] = {0};

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

void enqueue(struct node *p){
    if(rear == q_size-1){
        printf("Queue Overflow !");
        return;
    }
    else if(front == -1){
        front = rear = 0;
        queue[front] = p;
    }
    else{
        rear++;
        queue[rear] = p;
    }
}

struct node *dequeue(){
    if(front == -1 || front > rear){
        front = rear = -1;
        printf("Queue Underflow !");
        return NULL;
    }
    struct node* temp = queue[front]; 
    front++;
    return temp;
}

void BFS(int source){
    int i = source;
    while(front <= rear){
        if(i < g->v){
            if(visited[i] != 1){
                enqueue(g->adjList + i);
                visited[i] = 1;
            }
            i++;
        }
        struct node *temp_1 = dequeue(), *temp_2 = temp_1;
        printf("%d\n", temp_1->data);
        while(temp_2->next != temp_1){
            temp_2 = temp_2->next;
            if(visited[temp_2->index] != 1){
                enqueue(g->adjList + temp_2->index);
                visited[temp_2->index] = 1;
            }
        }
    }
}

void displayAdjList(){
    printf("The adj list is : \n");
    for(int i=0; i<data_size; i++){
        printf("%d  ", g->adjList[i].data);
        struct node *temp = g->adjList + i;
        while(temp->next != g->adjList + i){
            temp = temp->next;
            printf("%d ", temp->data);
        }
        printf("\n");
    }
}

int main(){
    g = myGraph(dataSet);
    // displayAdjList();
    BFS(1);
    return 0;
}