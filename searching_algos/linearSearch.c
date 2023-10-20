#include<stdio.h>
#define data_size 6

int linearSearch(int arr[], int arr_size, int target){
    for(int i=0; i<arr_size; i++){
        if(arr[i] == target)
            return i;
    }
    return -1;
}

int main(){
    int dataSet[data_size] = {103, 1226, 180, 19, 20, 215};
    int target = 19;
    int result = linearSearch(dataSet, data_size, target);
    if(result == -1)
        printf("Item not found !");
    else
        printf("Item is present at index %d", result);
        
    return 0;
}