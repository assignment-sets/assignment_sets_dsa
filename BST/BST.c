#include<stdio.h>
#include<stdlib.h>

struct BST{
    int data;
    struct BST *right;
    struct BST *left;
};

struct BST *root = NULL;

struct BST * createNode(){
    struct BST *newNode;
    newNode = (struct BST*)malloc(sizeof(struct BST));
    return newNode;
}

void insertNode(int data){
    struct BST *newNode = createNode(), *temp = root;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    if (root == NULL){
        root = newNode;
        return;
    }
    while(temp != newNode){
        if(data < temp->data){
            if(temp->left == NULL)
                temp->left = newNode;
            temp = temp->left;
        }
        else if(data > temp->data){
            if(temp->right == NULL)
                temp->right = newNode;
            temp = temp->right;
        }
        else{
            break;
        }
    }
}

void displayInOrder(struct BST* root) {
    if (root != NULL) {
        displayInOrder(root->left);
        printf("%d ", root->data);
        displayInOrder(root->right);
    }
}

int main(){
    insertNode(5);
    insertNode(4);
    insertNode(6);
    insertNode(3);
    insertNode(99);
    insertNode(-1);
    displayInOrder(root);
    return 0;
}