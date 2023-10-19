#include<stdio.h>
#define data_size 5

void swapVal(int i, int j, int arr[]){
    int k = arr[i];
    arr[i] = arr[j];
    arr[j] = k;
}

void selectionSort(int arr[], int arr_size){
    int min;
    for(int i=0; i<arr_size; i++){
        min = i;
        for(int j=i; j<arr_size; j++){
            if(arr[j] < arr[min])
                min = j;
        }
        swapVal(i, min, arr);
    }
}

int main(){
    int dataSet[data_size] = {33, 26, 42, 39, 11};

    selectionSort(dataSet, data_size);

    for(int i=0; i<data_size; i++)
        printf("%d ", dataSet[i]);

    return 0;
}