#include<stdio.h>
#define max_size 10

int front_1 = -1, rear_1 = -1, queue_1[max_size];
int front_2 = -1, rear_2 = -1, queue_2[max_size];

void enqueue(int data, int queue[], int *front, int *rear){
    if(*rear >= max_size-1){
        printf("Overflow !\n");
        return;
    }
    else if(*front == -1){
        *front = *rear = 0;
        queue[*front] = data;
    }
    else{
        (*rear)++;
        queue[*rear] = data;
    }
}

int dequeue(int queue[], int *front, int *rear){
    if(*front == -1 || *front > *rear){
        printf("Underflow !\n");
        return -1;
    }
    int deletedItem = queue[*front];
    (*front)++;
    return deletedItem;
}

void displayQueue(int queue[], int *front, int *rear){
    if(*front == -1 || *front > *rear){
        printf("Underflow !\n");
        return;
    }
    int i;
    for(i=*rear; i>=*front; i--){
        printf("%d\n", queue[i]);
    }
}

void push(int data){
    enqueue(data, queue_1, &front_1, &rear_1);
}

int pop(){
    if(front_1 == -1 || front_1 > rear_1){
        printf("Underflow !\n");
        return -1;
    }
    int poppedVal, items;
    while(front_1 < rear_1){
        items = dequeue(queue_1, &front_1, &rear_1);
        enqueue(items, queue_2, &front_2, &rear_2);
    }
    poppedVal = queue_1[rear_1];
    front_1 = rear_1 = -1;// reset the queue_1 to empty
    while(front_2 <= rear_2){
        items = dequeue(queue_2, &front_2, &rear_2);
        enqueue(items, queue_1, &front_1, &rear_1);
    }
    return poppedVal;
}

void displayStack(){
    displayQueue(queue_1, &front_1, &rear_1);
}

int main(){
    push(2);
    push(42);
    push(23);
    displayStack();
    pop();
    pop();
    displayStack();
    return 0;
}