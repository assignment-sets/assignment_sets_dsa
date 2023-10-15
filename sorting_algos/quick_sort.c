#include<stdio.h>
#define max 10

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int l, int r){
    int pivot = arr[l], i = l, j = r;
    while(i < j){
        while(arr[i] <= pivot)
            i++;
        while(arr[j] > pivot)
            j--;

        if(i < j)
            swap(arr, i, j);
    }
    swap(arr, l, j);
    return j;
}

void quickSort(int arr[], int l, int r){
    if(l < r){
        int j = partition(arr, l, r);
        quickSort(arr, l, j);
        quickSort(arr, j+1, r);
    }
}

int main(){
    int myArr[max] = {2, 5, 8, 9, 10, 1, 4, 3, 7, 6};
    quickSort(myArr, 0 , max-1);
    for(int i=0; i<max; i++){
        printf("%d ", myArr[i]);
    }
    return 0;
}