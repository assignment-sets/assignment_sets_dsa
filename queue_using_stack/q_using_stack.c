#include<stdio.h>
#define max_size 10

int top_1 = -1, top_2 = -1;
int stack_1[max_size], stack_2[max_size];

void push(int data, int stack[], int *top){
    if(*top == max_size - 1){
        printf("overflow !");
        return;
    }
    (*top)++;
    stack[*top] = data;
}

int pop(int stack[], int *top) {
    if (*top == -1) {
        printf("underflow !");
        return -1;
    }
    int temp = stack[*top];
    (*top)--;
    return temp;
}

void display(int stack[], int *top){
    if(*top == -1){
        printf("underflow !");
        return;
    }
    int j = *top, i;
    for(i=0; i<=j; i++){
        printf("%d ", stack[i]);
    }
}

void enqueue(int data){
    push(data, stack_1, &top_1);
}

int dequeue(){
    int poppedVal, transferData;
    while(top_1 >= 0){
        transferData = pop(stack_1, &top_1);
        push(transferData, stack_2, &top_2);
    }
    poppedVal = pop(stack_2, &top_2);
    while(top_2 >= 0){
        transferData = pop(stack_2, &top_2);
        push(transferData, stack_1, &top_1);
    }
    return poppedVal;
}
void displayQueue(){
    display(stack_1, &top_1);
    printf("\n");
}

int main(){
    enqueue(53);
    enqueue(53);
    enqueue(53);
    enqueue(53);
    enqueue(53);
    enqueue(53);
    enqueue(53);
    enqueue(53);
    enqueue(53);
    enqueue(53);
    enqueue(53);
    return 0;
}
