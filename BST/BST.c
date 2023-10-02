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

void insert(int data){
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

struct BST * search(int data){
    struct BST *temp = root;
    if(root == NULL)
        return NULL;
    while(temp != NULL){
        if(temp->data == data)
            break;
        else{
            if(data < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }
    }
    return temp;
}

struct BST * previousOf(int data){
    struct BST *temp = root, *prev;
    if(root == NULL || data == root->data)
        return NULL;
    while(temp != NULL){
        if(temp->data == data)
            break;
        prev = temp;
        if(data < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return prev;
}

struct BST * maxIn(struct BST *temp){
    struct BST *max;
    int maxVal = temp->data;
    while(temp->right != NULL){
        temp = temp->right;
        if(temp->data > maxVal)
            maxVal = temp->data;
    }
    max = search(maxVal);
    return max;
}


void delete(int data){
    struct BST *target = search(data);
    if(target->left == NULL && target->right == NULL){
        target = NULL;
    }
    else if(target->left != NULL && target->right != NULL){
        struct BST *maxLeftLeaf = maxIn(target->left);
        target->data = target->data + maxLeftLeaf->data;
        maxLeftLeaf->data = target->data - maxLeftLeaf->data;
        target->data = target->data - maxLeftLeaf->data;
        delete(maxLeftLeaf->data);
    }
    else{
        struct BST *nextOfTarget = target->left == NULL? target->right : target->left;
        target->data = nextOfTarget->data;
        nextOfTarget = NULL;
    }
}

void displayInOrder(struct BST* temp) {
    if (temp != NULL) {
        displayInOrder(temp->left);
        printf("%d ", temp->data);
        displayInOrder(temp->right);
    }
}

int main(){
    insert(10);
    insert(15);
    insert(20);
    insert(5);
    insert(2);
    insert(6);
    displayInOrder(root);
    delete(5);
    displayInOrder(root);
}