#include<stdio.h>
#define data_size 6

void insertionSort(int arr[], int arr_size){
    for(int i=1; i<arr_size; i++){
        int curr = arr[i], j = i-1;
        while(j >= 0 && curr < arr[j]){
            arr[j+1] = arr[j];
            j -= 1;
        }
        arr[j+1] = curr;
    }
}

int main(){
    int dataSet[data_size] = {55, 18897, 66, 1, 5, 88};

    insertionSort(dataSet, data_size);

    for(int i=0; i<data_size; i++)
        printf("%d ", dataSet[i]);
        
    return 0;
}