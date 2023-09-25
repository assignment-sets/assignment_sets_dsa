#include<stdio.h>
#include<string.h>
#define max 100

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
    char poppedVal = stack[top];
    top--;
    return poppedVal;
}

void removeSpaces(char userInput[], char finalInput[]){
    int i, j = 0;
    for (i = 0; userInput[i] != '\0'; i++) {
        if (userInput[i] != ' ') {
            finalInput[j++] = userInput[i];
        }
    }
    finalInput[j] = '\0';
}

void checkParanthesis(char finalInput[]){
    int i;
    for(i=0; i<strlen(finalInput)-1; i++){
        switch (finalInput[i])
        {
        case '(':
            push(finalInput[i]);
            break;
        case ')':
            pop();
            break;
        
        default:
            break;
        }
    }
    if(top == -1)
        printf("even number of paranthesis present in given exp !");
    else
        printf("un-even number of paranthesis present in given exp !");
}

int main(){
    char userInput[max], finalInput[max];
    printf("Enter the expression : ");
    fgets(userInput, sizeof(userInput), stdin);
    removeSpaces(userInput, finalInput);
    checkParanthesis(finalInput);
    return 0;
}