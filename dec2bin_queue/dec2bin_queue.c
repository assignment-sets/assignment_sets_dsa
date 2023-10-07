#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

struct node *createNode(){
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    return newNode;
}

void enqueue(int data){
    struct node *newNode = createNode();
    newNode->data = data;
    newNode->next = NULL;
    if(front == NULL){
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

int dequeue(){
    if(front == NULL){
        printf("Underflow !");
        return -1;
    }
    struct node *prevFront = front;
    int deletedItem = prevFront->data;
    front = front->next;
    free(prevFront);
    return deletedItem;
}

void dec2bin(int n){
    enqueue(1);
    printf("Binary values from 1 to %d are : \n", n);
    while(n != 0){
        int poppedVal;
        poppedVal = dequeue();
        printf("%d ", poppedVal);
        enqueue(poppedVal*10);
        enqueue((poppedVal*10)+1);
        n--;
    }
}

int main(){
    int n;
    printf("Enter the nth term : ");
    scanf("%d", &n);
    dec2bin(n);
    return 0;
}
