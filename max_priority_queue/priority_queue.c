#include<stdio.h>
#define max_size 10

int queue[max_size], front = -1, rear = -1;

void shift(int index){
    int i;
    for(i=rear; i>index; i--){
        queue[i] = queue[i-1];
    }
}

void enqueue(int data){
    if(rear == max_size-1){
        printf("\nOverflow !\n");
        return;
    }
    else if(front == -1){
        front = rear = 0;
        queue[front] = data;
    }
    else{
        rear++;
        int i, count = 0;
        for(i=front; i<rear; i++){
            if(data > queue[i]){
                shift(i);
                queue[i] = data;
                count++;
                break;
            }
        }
        if(count == 0)
            queue[rear] = data;
    }
}

int dequeue(){
    if(front == -1 || front > rear){
        printf("\nUnderflow !\n");
        return -1;
    }
    front++;
}

void display(){
    if(front == -1 || front > rear){
        printf("\nUnderflow !\n");
        return;
    }
    int i = front;
    printf("\nQueue items are : \n");
    while(i <= rear){
        printf("%d ", queue[i]);
        i++;
    }
}

int main(){
    enqueue(5);
    enqueue(7);
    enqueue(9);
    enqueue(3);
    display();
    dequeue();
    display();
    return 0;
}