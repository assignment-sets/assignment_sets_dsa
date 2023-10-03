#include<stdio.h>
#define max_size 10

int top = -1;
int stack_1[max_size], stack_2[max_size];

void push(int data, int stack[]){
    if(top == max_size - 1)
        return;
    top++;
    stack[top] = data;
}

int pop(int stack[]){
    if(top == -1)
        return -1;
    int temp = stack[top];
    top--;
    return temp;
}

void display(int stack[]){
    if(top == -1)
        return;
    while(top != -1){
        printf("%d\n", stack[top]);
        top--;
    }
}

int main(){
    push(2, stack_1);
    push(78, stack_1);
    push(1078, stack_1);
    push(27, stack_1);
    return 0;
}