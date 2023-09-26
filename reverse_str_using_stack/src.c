// Write a program to reverse a string using stack

#include<stdio.h>
#include<string.h>
#define max 50

// global var declaration
int top = -1;
char stack[max];

void push(char x){
    if(top == max-1){
        printf("stack overflow !");
        return;
    }
    top++;
    stack[top] = x;
}

char pop(){
    if(top == -1){
        printf("stack underflow !");
        return '\0';
    }
    char poppedval = stack[top];
    top--;
    return poppedval;
}

void reverseString(char userInput[], char reversedString[]){
    int i, j=0;
    for(i=0; i<strlen(userInput)-1; i++){
        push(userInput[i]);
    }
    while(top != -1){
        reversedString[j++] = pop();
    }
    printf("the reversed string is : %s", reversedString);
}

int main(){
    char userInput[max], reversedString[max];

    printf("Enter a string to reverse : ");
    fgets(userInput, sizeof(userInput), stdin);

    reverseString(userInput, reversedString);

    return 0;
}