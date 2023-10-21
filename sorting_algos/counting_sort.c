#include<stdio.h>
#define data_size 6
#define max_item 5

void selectionSort(int arr[], int arr_size){
    int i;
    int count[max_item] = {0}, newArr[data_size];

    for(i=0; i<arr_size; i++)
        ++count[arr[i]];

    for(i=1; i<max_item; i++)
        count[i] = count[i] + count[i-1];

    for(i=arr_size-1; i>=0; i--){
        newArr[--count[arr[i]]] = arr[i];
    }

    for(i=0; i<arr_size; i++){
        arr[i] = newArr[i];
    }
}

int main(){
    int dataSet[data_size] = {2, 1, 3, 3, 4, 2};

    selectionSort(dataSet, data_size);

    for(int i=0; i<data_size; i++)
        printf("%d ", dataSet[i]);

    return 0;
}