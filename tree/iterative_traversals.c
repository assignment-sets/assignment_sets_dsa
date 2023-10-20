#include<stdio.h>
#include<stdlib.h>
#define input_size 13

//gloval vars declaration
int keyVal = 0;
struct node *root = NULL;
int visitedKeys[input_size] = {0};
struct node *result[input_size];

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

int allVisited(){
    for(int i=0; i<input_size; i++){
        if(visitedKeys[i] == 0)
            return 0;
    }
    return 1;
}

struct node *prevOf(struct node *target){
    struct node *temp = root, *prev;
    if(root == NULL || target == root)
        return NULL;
    while(temp != NULL){
        if(temp == target)
            break;
        prev = temp;
        if(target->data < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return prev;
}

void inorderIterative(struct node *myRoot){
    struct node *temp = myRoot;
    int i=0;
    while(!allVisited()){
        while(temp->left != NULL && visitedKeys[temp->left->key] != 1){
            temp = temp->left;
        }
        if(visitedKeys[temp->key] != 1){
            result[i++] = temp;
            visitedKeys[temp->key] = 1;
        }
        if(temp->right != NULL && visitedKeys[temp->right->key] != 1)
            temp =temp->right;
        else
            temp = prevOf(temp);
    }
}

int main(){
    int inputSet[input_size] = {15, 10, 20, 5, 13, 18, 25, 3, 7, 12, 16, 22, 30};

    for(int i=0; i<input_size; i++)
        insertNode(inputSet[i]);

    inorderIterative(root);
    
    for(int j=0; j<input_size; j++)
        printf("%d ", result[j]->data);

    return 0;
}