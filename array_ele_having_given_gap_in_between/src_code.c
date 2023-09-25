//Find pairs with specified difference in an array 

#include<stdio.h>

int substractedVal;

int modOfDiff(int a, int b){
    substractedVal = a - b;
    if(substractedVal < 0)
        substractedVal = -substractedVal;
    return substractedVal;
}

void itemsHavingSpecifiedDiff(int arr[], int size, int diff){
    printf("Pairs of items having specified diff between them are : \n");
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(modOfDiff(arr[i], arr[j]) == diff)
                printf("(%d, %d)\n",arr[i], arr[j]);
        }
    }
}

int main(){
    int size, diff;
    printf("Enter size of array : ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the array items : ");
    for(int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }
    printf("Specify the difference : ");
    scanf("%d", &diff);
    if(diff < 0){
        printf("Diff can't be nagative !");
        return 1;
    }
    itemsHavingSpecifiedDiff(arr, size, diff);
    return 0;
}