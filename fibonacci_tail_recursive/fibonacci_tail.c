#include <stdio.h>

long long int tail_recursive_fibonacci(int n, long long int a, long long int b) {
    if (n == 0) {
        return a;
    }
    printf("%lld ", a); // Print the current Fibonacci number
    return tail_recursive_fibonacci(n - 1, b, a + b);
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1;
    }

    printf("Fibonacci Series up to %d: ", n);
    tail_recursive_fibonacci(n, 0, 1);
    printf("\n");

    return 0;
}
