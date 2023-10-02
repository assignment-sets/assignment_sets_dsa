#include<stdio.h>

void towerOfHanoi(int n, char beg, char aux, char end){
    if(n >= 1){
        towerOfHanoi(n-1, beg, end, aux);
        printf("move disk from %c to %c\n", beg, end);
        towerOfHanoi(n-1, aux, beg, end);
    }
}

int main(){
    int numOfDisk;
    char beg = 'A', aux = 'B', end = 'C';
    printf("Enter the number of disks : ");
    scanf("%d", &numOfDisk);
    towerOfHanoi(numOfDisk, beg, aux, end);
    return 0;
}