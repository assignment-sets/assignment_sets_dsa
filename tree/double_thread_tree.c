#include<stdio.h>
#include<stdlib.h>
#define input_size 7

int keyVal = 0;
struct node *root = NULL;
struct node *inorderTrv[input_size];

struct node{
    int data, key;
    struct node *left, *right;
};

struct node *createNode(){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    return newNode;
}

void insertNode(int data){
    struct node *newNode = createNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->key = keyVal++;

    if(root == NULL){
        root = newNode;
    }
    struct node *temp = root;
    while(1){
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
        else
            return;
    }
}

void inorder(struct node *myRoot){
    if(myRoot == NULL)
        return;
    int i = 0;
    inorder(myRoot->left);
    inorderTrv[i++] = myRoot;
    inorder(myRoot->right);
}

struct node *successorOf(struct node *target){
    int i;
    for(i=0; i<input_size; i++){
        if(inorderTrv[i] == target)
            break;
    }
    if(i >= input_size - 1)
        return NULL;

    return inorderTrv[i+1];
}

struct node *predecessorOf(struct node *target){
    int i;
    for(i=0; i<input_size; i++){
        if(inorderTrv[i] == target)
            break;
    }
    if(i <= 0)
        return NULL;

    return inorderTrv[i-1];
}

void doubleThread(struct node *temp){
    if(temp == NULL)
        return;
    
    doubleThread(temp->left);
    if(temp->left == NULL){
        temp->left = predecessorOf(temp);
    }
    if(temp->right == NULL){
        temp->right = successorOf(temp);
    }
    doubleThread(temp->right);
}

int main(){
    int inputSet[input_size] = {5, 3, 4, 1, 7, 6, 8};

    for(int i=0; i<input_size; i++)
        insertNode(inputSet[i]);

    doubleThread(root);
    display(root);

    return 0;
}