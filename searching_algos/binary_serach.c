#include<stdio.h>
#define size 10

int binarySearchIterative(int arr[], int arr_size, int key){
    int l = 0, h = arr_size - 1, mid;

    while(l <= h){
        mid = (l + h) / 2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] > key)
            h = mid - 1;
        else
            l = mid + 1;
    }

    return -1;
}

int binarySearchRecursive(int arr[], int key, int l, int h){
    if(l > h)
        return -1;

    int mid = (l + h) / 2;

    if(arr[mid] == key)
        return mid;

    if(arr[mid] > key)
        return binarySearchRecursive(arr, key, l, mid-1);
    
    return binarySearchRecursive(arr, key, mid+1, h);
}

int main(){
    int myArray[size] = {1,2,3,4,5,6,7,8,9,10}, itemIndex, key = 4;
    // itemIndex = binarySearchIterative(myArray, size, key);
    itemIndex = binarySearchRecursive(myArray, key, 0, size-1);
    printf("%d is at %d index of given array !", myArray[itemIndex], itemIndex);
    return 0;
}