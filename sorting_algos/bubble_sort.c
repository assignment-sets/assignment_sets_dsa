#include<stdio.h>
#define data_size 6

void swap(int *arr, int a, int b){
    int c = arr[a];
    arr[a] = arr[b];
    arr[b] = c;
}

void bubbleSort(int *arr, int arr_size){
    for(int i=0; i<arr_size-1; i++){
        for(int j=0; j<arr_size-1-i; j++){
            if(arr[j] > arr[j+1])
                swap(arr, j, j+1);
        }
    }
}

int main(){
    int dataSet[data_size] = {5, 34, 6, 88, 103, 88};
    bubbleSort(dataSet, data_size);
    for(int i=0; i<data_size; i++){
        printf("%d ", dataSet[i]);
    }
    return 0;
}