#include<stdio.h>

int factorial(int n, int result){
    if(n == 0)
        return result;
    factorial(n-1, (n*result));
}

int main(){
    int n, result;
    printf("Enter a number : ");
    scanf("%d", &n);
    result = factorial(n, 1);
    printf("The factorial of given num is : %d", result);
    return 0;
}