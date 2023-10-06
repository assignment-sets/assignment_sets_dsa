#include<stdio.h>
#define max_Size 11

int front, right_rear, left_rear, queue[max_Size];
front = right_rear = left_rear = -1;

void enqueue(int data){
    if(front == -1){
        front = right_rear = left_rear = max_Size/2;
        queue[front] = data;
    }
    else{
        int ch;
        printf("1.insert from left\n2.insert from right\nchoose(1/2):");
        switch (ch)
        {
        case 1:
            if(right_rear == max_Size-1){
                printf("overflow !");
                return;
            }
            right_rear++;
            queue[right_rear] = data;
            break;
        case 2:
            if(left_rear == 0){
                printf("overflow !");
                return;
            }
            left_rear--;
            queue[left_rear] = data;
            break;
        
        default:
            printf("Invalid Input !");
            return;
        }
    }
}

int dequeue(){
    if(front == -1){
        printf("underflow !");
        return;
    }
}

int main(){
    return 0;
}