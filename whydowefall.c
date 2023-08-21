#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

struct node * createNode(){
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    return new_node;
}

int userInput(){
    int data;
    printf("Enter an integer : ");
    scanf("%d", &data);
    return data;
}

void insertNode(int data){
    struct node *new_node = createNode();
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    if(head == NULL){
        head = new_node;
    }
    else{
        struct node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}

void reverseFromMid(int count){
    if(head == NULL)
        printf("List is empty !");
    else{
        struct node *mid_node = head, *temp, *lst_node = head;

        while(lst_node->next != NULL)
            lst_node = lst_node->next;

        for(int i=0; i<(count/2); i++){
            mid_node = mid_node->next;
        }

        printf("the result is :\n");

        temp = mid_node->prev;
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->prev;
        }

        temp = lst_node;
        while(temp != mid_node->prev){
            printf("%d ", temp->data);
            temp = temp->prev;
        }
    }
}

int main(){
    int permit = 1, count_of_nodes = 0;
    while(permit){
        int ch;
        printf("press 1 to add and 0 to exit : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            count_of_nodes = count_of_nodes + 2;
            insertNode(userInput());
            insertNode(userInput());
            break;
        case 0:
            permit = 0;
            break;
        default:
            break;
        }
    }
    reverseFromMid(count_of_nodes);
    return 0;
}