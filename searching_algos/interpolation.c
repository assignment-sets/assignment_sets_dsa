#include<stdio.h>
#define data_size 5

int interpolation(int arr[], int arr_size, int target){
    int low = 0;
    int high = arr_size - 1;
    while(low < high){
        int probe = low + (high - low) * (target - arr[low]) / (arr[high] - arr[low]);
        if(arr[probe] == target)
            return probe;
        else if(arr[probe] < target)
            low = probe + 1;
        else
            high = probe - 1;
    }
    return -1;
}

int main(){
    int dataSet[data_size] = {1, 2, 4, 8, 16};
    int target, result;
    printf("Enter the target item : ");
    scanf("%d", &target);
    result = interpolation(dataSet, data_size, target);
    printf("Target item is found in %d index", result);
    return 0;
}