#include<stdio.h>
#define arr_size 7

void merge(int l, int h, int mid, int arr[]){
    int newArr[arr_size], i = l, j = mid+1, k = l;

    while(i <= mid && j <= h){
        if(arr[i] <= arr[j])
            newArr[k++] = arr[i++];
        else
            newArr[k++] = arr[j++];
    }

    for(;i <= mid; i++)
        newArr[k++] = arr[i];
    for(;j <= h; j++)
        newArr[k++] = arr[j];

    for(k=l; k <= h; k++)//cloning the sorted subarray in the main array
        arr[k] = newArr[k];
}

void mergeSort(int l, int h, int arr[]){
    if(l < h){
        int mid = (l + h) / 2;
        mergeSort(l, mid, arr);
        mergeSort(mid+1, h, arr);
        merge(l, h, mid, arr);
    }
}

int main(){
    int dataSet[arr_size] = {88, 495, 11, 2, 69, 54, 1001};

    mergeSort(0, (arr_size - 1), dataSet);

    for(int i=0; i<arr_size; i++)
        printf("%d ", dataSet[i]);

    return 0;
}