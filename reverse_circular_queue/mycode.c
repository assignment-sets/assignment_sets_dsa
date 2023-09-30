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
        printf("\nQueue is full !\n");
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
        printf("\nQueue is empty !\n");
        return;
    }
    struct node *previousFront = front;
    front = front->next;
    free(previousFront);
}

void displayQueue(){
    if (front == NULL) {
        printf("\nQueue is empty !\n");
        return;
    }

    struct node *temp = front;
    printf("\nThe items are : \n\n");
    while(temp != rear){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

void reverseQueue(){
    if(item_count == max_size){
        struct node *newFront = rear, *newRear = NULL, *temp = front;
        while(newRear != front){
            newRear = temp->next;
            temp->next = newFront;
            newFront = temp;
            temp = newRear;
        }
        rear = newRear;
        front = newFront;
    }else{
        struct node *newFront = NULL, *t2 = NULL, *temp = front;
        while(temp != NULL){
            t2 = temp->next;
            temp->next = newFront;
            newFront = temp;
            temp = t2;
        }
        rear = front;
        front = newFront;
        free(t2);
        free(temp);
    }
}

int main(){
    enqueue(22);
    enqueue(2);
    enqueue(500);
    enqueue(33);
    enqueue(678);
    enqueue(2);
    enqueue(5020);
    enqueue(1);
    enqueue(78);
    enqueue(23);
    enqueue(3);
    displayQueue();
    reverseQueue();
    displayQueue();
    return 0;
}
