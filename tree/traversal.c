#include<stdio.h>
#include<stdlib.h>
#define input_size 7

struct node{
    int data;
    struct node *left, *right;
};

struct node *root = NULL;

struct node *createNode(){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    return newNode;
}

void insertNode(int data){
    struct node *newNode = createNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if(root == NULL)
        root = newNode;

    struct node *temp = root;
    while(1){
        if(data < temp->data){
            if(temp->left == NULL){
                temp->left = newNode;
                break;
            }
            temp = temp->left;
        }
        else if(data > temp->data){
            if(temp->right == NULL){
                temp->right = newNode;
                break;
            }
            temp = temp->right;
        }
        else    
            return;
    }
}

void inOrderDisplay(struct node *myRoot){
    if(myRoot == NULL)
        return;

    inOrderDisplay(myRoot->left);
    printf("%d ", myRoot->data);
    inOrderDisplay(myRoot->right);
}

void preOrderDisplay(struct node *myRoot){
    if(myRoot == NULL)
        return;

    printf("%d ", myRoot->data);
    preOrderDisplay(myRoot->left);
    preOrderDisplay(myRoot->right);
}

void postOrderDisplay(struct node *myRoot){
    if(myRoot == NULL)
        return;

    postOrderDisplay(myRoot->left);
    postOrderDisplay(myRoot->right);
    printf("%d ", myRoot->data);
}

int main(){
    int inputSet[input_size] = {5,2,3,4,1,6,7};

    for(int i=0; i<input_size; i++)
        insertNode(inputSet[i]);

    postOrderDisplay(root);

    return 0;
}