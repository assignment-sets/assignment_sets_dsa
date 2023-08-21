#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int data;
	struct node *link;
};
struct node *head = NULL;

struct node* create_node(){
	struct node *new_node;
	new_node = (struct node*)malloc(sizeof(struct node));
    return new_node;
}

void insert_node(struct node *new_node){
    printf("Enter the data : ");
    scanf("%d", &new_node->data);
    if(head == NULL){
        head = new_node;
        new_node->link = head;
    }
    else{
        struct node *temp = head;
        while(temp->link != head){
            temp = temp->link;
        }
        temp->link = new_node;
        new_node->link = head;
    }
    printf("Successfully created a new node !");
}

void display_node(){
    if(head == NULL){
        printf("List is empty !");
    }
    else{
        struct node *temp = head;
        printf("The list items are :\n");
        while(temp->link != head){
            printf("%d\n", temp->data);
            temp = temp->link;
        }
        printf("%d", temp->data);
    }
}

void is_looped(){
    struct node *temp = head;
    while (temp->link != NULL)
    {
        if(temp->link == head){
            printf("This list is looped !");
            break;
        }
        temp = temp->link;
    }
    if(temp->link == NULL)
        printf("This list isn't looped !");
}

int main(){
    int ch;
    
    while(1){
        printf("\nMENU : \n1.create node\n2.display\n3.check loop\n4.exit\nChoose an option(1/2/3/4): ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                insert_node(create_node());
                break;
            case 2:
                display_node();
                break;
            case 3:
                is_looped();
                break;
            case 4:
                exit(1);
                break;
            
            default:
                printf("Invalid input...plsz choose between 1/2/3/4 !");
                break;
        }
    }

    return 0;
}