//creating a doubly linked list

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

void insertNode(struct node * new_node){
    int choice, permit = 1, target;
    struct node *temp = head, *prev_temp, *lst_node = head;

    printf("data (integer only !) : ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;

    if(head == NULL){
        head = new_node;
        new_node->prev = NULL;
    }
    else{
        while(lst_node->next != NULL){
            lst_node = lst_node->next;
        }

        printf("1.insert at begining\n2.insert at end\n3.insert at intermediate position\nchoose one : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
            break;
        case 2:
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->prev = temp;
            break;
        case 3:
            while(1){
                printf("Enter the value of the data before which new node to be inserted : ");
                scanf("%d", &target);
                if(head->prev == NULL && head->next->next == NULL){
                    printf("%d is not a intermediate item !\n",target);
                    permit = 0;
                    break;
                }
                else if(target == head->data || target == lst_node->data){
                    printf("only intermediate data is allowed !\n");
                    continue;
                }
                else{
                    while(temp->data != target){
                        prev_temp = temp;
                        temp = temp->next;
                    }
                    new_node->prev = prev_temp;
                    new_node->next = temp;
                    prev_temp->next = new_node;
                    temp->prev = new_node;
                    break;
                }
            }
            break;
        
        default:
            printf("invalid input !");
            break;
        }
    }
    if(permit){
        printf("succesfully inserted !");
    }
}

void displayNode(){
    if(head == NULL){
        printf("List is empty !\n");
    }
    else{
        struct node *ptr = head;
        printf("The items are : \n");
        while(ptr != NULL){
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}

void displayReverse(){
    if(head == NULL){
        printf("List is empty !\n");
    }
    else{
        struct node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        printf("The elements in reverse order is :\n");
        while(temp != NULL){
            printf("%d\n", temp->data);
            temp = temp->prev;
        }
    }
}

void deleteNode(){
    if(head == NULL)
        printf("Nothing to delete !");
    else{
        struct node *del = head, *prev_del ,*lst_node = head;
        int choice, target, permit = 1;
        while(lst_node->next != NULL){
            lst_node = lst_node->next;
        }
        if(lst_node == head){
            head = NULL;
            free(lst_node);
        }
        else{
            printf("1.delete from last\n2.delete from the begining\n3.delete from intermediate position\nChoice : ");
            scanf("%d", &choice);
            switch (choice)
            {
                case 1:
                    while(del->next != NULL){
                        prev_del = del;
                        del = del->next;
                    }
                    prev_del->next = NULL;
                    free(del);
                    break;
                case 2:
                    head = head->next;
                    head->prev = NULL;
                    free(del);
                    break;
                case 3:
                    while(1){
                        printf("Enter the value of the data to delete : ");
                        scanf("%d", &target);
                        if(head->prev == NULL && head->next->next == NULL){
                            printf("%d is not a intermediate item !\n",target);
                            permit = 0;
                            break;
                        }
                        else if(target == head->data || target == lst_node->data){
                            printf("only intermediate data is allowed !\n");
                            continue;
                        }
                        else{
                            while(del->data != target){
                                prev_del = del;
                                del = del->next;
                            }
                            prev_del->next = del->next;
                            del->next->prev = prev_del;
                            free(del);
                            break;
                        }
                    }
                    break;
                
                default:
                    printf("invalid input !");
                    break;
            }
        }
        if(permit){
            printf("succesfully deleted !");
        }
    }
}

int main(){
    while(1){
        int ch;
        printf("\nMENU\n1.insert node\n2.display node\n3.display reversed\n4.delete node\n5.exit\nPlease choose one : ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                insertNode(createNode());
                break;
            case 2:
                displayNode();
                break;
            case 3:
                displayReverse();
                break;
            case 4:
                deleteNode();
                break;
            case 5:
                exit(1);
                break;

            default :
                printf("invalid input !\n");
        }
    }
    return 0;
}