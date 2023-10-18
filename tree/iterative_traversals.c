#include<stdio.h>
#include<stdlib.h>
#define input_size 7
#define stack_size 50

//gloval vars declaration
struct node *stack[stack_size];
int top = -1, keyVal = 0;
struct node *root = NULL;
int visitedKeys[stack_size] = {0};
struct node *result[stack_size];

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
    newNode->key = keyVal;

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

void push(struct node *myNode){
    if(top == stack_size - 1)
        return;
    top++;
    stack[top] = myNode;
}

struct node *pop(){
    if(top == -1)
        return NULL;
    struct node *deletedNode = stack[top];
    top--;
    return deletedNode;
}

void loadStack(struct node *myRoot){
    struct node *temp = myRoot;
    while(temp != NULL){
        push(temp);
        visitedKeys[temp->key] = 1;
        temp = temp->left;
    }
}

void inorderIterative(struct node *myRoot){
    int i = 0;
    loadStack(myRoot);
    while(top != -1){
        struct node *poppedVal = pop();
        result[i++] = poppedVal;
        if(poppedVal->left != NULL && visitedKeys[poppedVal->left->key] != 1){
            push(poppedVal->left);
            visitedKeys[poppedVal->right->key] = 1;
        }
        else if(poppedVal->right != NULL && visitedKeys[poppedVal->right->key] != 1){
            push(poppedVal->right);
            visitedKeys[poppedVal->right->key] = 1;
        }
    }
}

int main(){
    int inputSet[input_size] = {5,2,3,4,1,6,7};

    for(int i=0; i<input_size; i++)
        insertNode(inputSet[i]);

    inorderIterative(root);
    
    for(int j=0; j<input_size; j++)
        printf("%d ", result[j]->data);

    return 0;
}