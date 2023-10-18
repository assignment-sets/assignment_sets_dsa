#include<stdio.h>
#include<stdlib.h>

struct tree{
    int data;
    struct tree *right, *left, *prev;
};

struct tree *root = NULL;

struct tree *createNode(){
    struct tree *newNode = (struct tree *)malloc(sizeof(struct tree));
    return newNode;
}

void insertNode(int data){
    struct tree *newNode = createNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    if(root == NULL){
        root = newNode;
        newNode->prev = NULL;
        return;
    }
    else{
        struct tree *temp = root;
        while(1){
            if(data == temp->data)
                return;

            if(data > temp->data){
                if(temp->right == NULL){
                    temp->right = newNode;
                    newNode->prev = temp;
                    break;
                }
                temp = temp->right;
            }

            if(data < temp->data){
                if(temp->left == NULL){
                    temp->left = newNode;
                    newNode->prev = temp;
                    break;
                }
                temp = temp->left;
            }
        }
    }
}

void displayInOrder(struct tree* temp) {//to display the tree in incrementing order
    if (temp != NULL) {
        displayInOrder(temp->left);
        printf("%d ", temp->data);
        displayInOrder(temp->right);
    }
}

int balanceFactorOf(struct tree *myRoot){
    int heightLeft = 0, heightRight = 0;
    struct tree *temp = myRoot;

    while (temp->left != NULL){
        temp = temp->left;
        heightLeft++;
    }

    temp = myRoot;

    while (temp->right != NULL){
        temp = temp->right;
        heightRight++;
    }
    printf("%d\n%d\n", heightLeft, heightRight);
    return (heightLeft - heightRight);
}

int main(){
    insertNode(5);
    insertNode(20);
    insertNode(2);
    insertNode(3);
    insertNode(1);
    // displayInOrder(root);
    int n = balanceFactorOf(root);
    printf("\n%d", n);
    return 0;
}