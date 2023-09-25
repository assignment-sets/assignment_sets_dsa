#include<stdio.h>
#include<string.h>
#include<math.h>
#define max 100

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

char pop(){
    if(top == -1){
        printf("stack underflow !");
        return '\0';
    }
    int poppedVal = stack[top];
    top--;
    return poppedVal;
}

int precedenceOf(char currentItem){
    switch (currentItem)
    {
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '^':
        return 3;
    default:
        return 0;
        break;
    }
}

void removeSpaces(char infix[], char finalInfix[]){
    int i, j = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        if (infix[i] != ' ') {
            finalInfix[j++] = infix[i];
        }
    }
    finalInfix[j] = '\0';
}

void infix2postfix(char infix[], char postfix[]){
    int i, j = 0;
    for(i=0; i<(strlen(infix)-1); i++){
         char currentItem = infix[i], poppedVal;
         switch (currentItem){
            case '(':
                push(currentItem);
                break;
            case ')':
                while((poppedVal = pop()) != '('){
                    postfix[j++] = poppedVal;
                }
            break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                if(top == -1)
                    push(currentItem);
                else{
                    while(precedenceOf(currentItem) <= precedenceOf(stack[top])){
                        postfix[j++] = pop();
                    }
                    push(currentItem);
                }
                break;
            default:
                postfix[j++] = currentItem;
         }
    }

    while(top != -1){
        postfix[j++] = pop();
    }
    postfix[j] = '\0';

    printf("Eqv postfix is : ");
    puts(postfix);
}

void postEval(char postfix[]){
    int i, result;
    
    for(i=0; i<strlen(postfix); i++){
        if(postfix[i] >= '0' && postfix[i] <= '9'){
            push(postfix[i] - '0');
        }
        else{
            int last, secondLast;
            last = pop();
            secondLast = pop();
            switch (postfix[i])
            {
                case '+':
                    result = secondLast + last;
                    push(result);
                    break;
                case '-':
                    result = secondLast - last;
                    push(result);
                    break;
                case '*':
                    result = secondLast * last;
                    push(result);
                    break;
                case '/':
                    result = secondLast / last;
                    push(result);
                    break;
                case '^':
                    result = pow(secondLast, last);
                    push(result);
                    break;
                
                default:
                    break;
            }
        }
    }

    printf("The evaluation of postfix is : %d", result);
}

int main(){
    char infix[max], postfix[max], finalInfix[max];

    printf("Enter the infix exp : ");
    fgets(infix, sizeof(infix), stdin);

    removeSpaces(infix, finalInfix);

    infix2postfix(finalInfix, postfix);

    postEval(postfix);

    return 0;
}