// remove char from doubly list

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct node{
    char data;
    struct node *prev, *next;
};

struct node *head = NULL; // global declaration of head pointer of list

struct node * createNode(){
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    return new_node;
}

char validatedInput(){
    char data;
    while(1){
        printf("Enter a char : ");
        scanf("%c", &data);
        data = toupper(data);
        if(data >= 'A' && data <= 'Z')
            break;
        else{
            printf("Only single characters allowed !\n");
            continue;
        }
    }
    return data;
}

void insertNode(){
    struct node *new_node = createNode();
    new_node->data = validatedInput();
    new_node->next = NULL;
    new_node->prev = NULL;
    if(head == NULL)
        head = new_node;
    else{
        struct node *temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = new_node;
        new_node->prev = temp;
    }
    printf("Successfully inserted a new node !\n");
}

void displayNode(){
    if(head == NULL)
        printf("List is empty !\n");
    else{
        struct node *temp = head;
        printf("The lsit items are :\n");
        while(temp != NULL){
            printf("%c\n", temp->data);
            temp = temp->next;
        }
    }
}

void deleteNode(){
    if(head == NULL)
        printf("Nothing to delete !\n");
    else if(head->prev == NULL && head->next == NULL){
        free(head);
        head = NULL;
    }
    else{
        struct node *del = head;
        char target;
        printf("Enter the character to delete : ");
        scanf("%c", &target);
        target = toupper(target);
        while(del->data != target){
            del = del->next;
        }
        del->prev->next = del->next;
        del->next->prev = del->prev;
        free(del);
    }
}

int main(){
    while(1){
        int ch;
        printf("\nMENU : \n1.insert node\n2.delete node\n3.display node\n4.exit\nChoose one : ");
        scanf("%d", &ch);
        getchar();
        switch(ch){
            case 1:
                insertNode();
                break;
            case 2:
                deleteNode();
                break;
            case 3:
                displayNode();
                break;
            case 4:
                exit(1);
                break;
            default:
                printf("invalid input! (choose between 1/2/3/4)\n");
        }
    }
    return 0;
}