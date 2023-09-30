#include<stdio.h>
#include<stdlib.h>
#define max_size 10

struct node{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;
int item_count = 0;

struct node *createNode(){
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    return newNode;
}

void enqueue(int data){
    if(rear != NULL && rear->next == front){
        printf("Queue is full !\n");
    }else{
        item_count++;
        struct node *newNode = createNode();
        newNode->data = data;
        newNode->next = NULL;
        if(front == NULL){
            front = rear = newNode;
        }else{
            struct node *currentLastNode = front;
            while(currentLastNode->next != NULL)
                currentLastNode = currentLastNode->next;
            currentLastNode->next = newNode;
            rear = newNode;
            if(item_count == max_size)
                rear->next = front;
        }
    }
}

void dequeue(){
    if(front == NULL){
        printf("Queue is empty !\n");
        return;
    }
    struct node *previousFront = front;
    front = front->next;
    free(previousFront);
}

void displayQueue(){
    if (front == NULL) {
        printf("The queue is empty.\n");
        return;
    }

    struct node *temp = front;
    printf("The items are : \n");
    while(temp != rear){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

int main(){
    enqueue(22);
    enqueue(2);
    enqueue(500);
    displayQueue();
    dequeue();
    dequeue();
    displayQueue();
    return 0;
}
