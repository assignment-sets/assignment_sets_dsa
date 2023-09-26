// Write a program to convert a decimal number into binary number using stack. 

#include<stdio.h>
#include<string.h>
#define max 100

// global var declaration
int top = -1;
int stack[max];

void push(int x){
    if(top == max-1){
        printf("stack overflow !");
        return;
    }
    top++;
    stack[top] = x;
}

int pop(){
    if(top == -1){
        printf("stack underflow !");
        return '\0';
    }
    int poppedval = stack[top];
    top--;
    return poppedval;
}

void decimal2bin(int decimal){
    int rem, binDigitSize;

    while(decimal != 0){
        rem = decimal%2;
        push(rem);
        decimal = decimal/2;
    }

    binDigitSize = top + 1;
    int binary[binDigitSize], i = 0;
    while (top != -1)
        binary[i++] = pop();

    printf("Binary : ");
    for(i=0; i<binDigitSize; i++)
        printf("%d", binary[i]);
}

int main(){
    int decimalInput;

    printf("Enter the decimal value : ");
    scanf("%d", &decimalInput);

    decimal2bin(decimalInput);

    return 0;
}