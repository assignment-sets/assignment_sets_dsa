#include<stdio.h>
#include<stdlib.h>

struct BST{//structure for each node of BST
    int data;
    struct BST *right;
    struct BST *left;
};

struct BST *root = NULL;//global declaration & initialization of main root node of BST

struct BST * createNode(){//creates new node for tree using malloc
    struct BST *newNode;
    newNode = (struct BST*)malloc(sizeof(struct BST));
    return newNode;
}

void insert(int data){//inserts newly created node into the appropriate position of BST
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

struct BST * search(int data, struct BST *myRoot){//returns address of target node withing tree or subtree
    struct BST *temp = myRoot;
    if(myRoot == NULL)
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

struct BST * previousOf(int data, struct BST *myRoot){//returns address of previous node to the current node withing tree or subtree
    struct BST *temp = myRoot, *prev;
    if(myRoot == NULL || data == myRoot->data)
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

struct BST * maxIn(struct BST *temp){//returns address of node holding max data of specified tree or subtree
    struct BST *max;
    int maxVal = temp->data;
    while(temp->right != NULL){
        temp = temp->right;
        if(temp->data > maxVal)
            maxVal = temp->data;
    }
    max = search(maxVal, temp);
    return max;
}

void updateParent(struct BST *prevOfTarget, struct BST *target, struct BST *newVal){//to update the leaf of parent of the target to be deleted

    if(prevOfTarget->left == target)
        prevOfTarget->left = newVal;

    else
        prevOfTarget->right = newVal;
}

void delete(int data, struct BST *myRoot){

    struct BST *target = search(data, myRoot), *prevOfTarget = previousOf(data, myRoot);

    if(root == NULL)//if no node is present
        return;

    else if(target == root)//if only one node is present
        root = NULL;

    else if(target->left == NULL && target->right == NULL){//if the target node is leaf node
        updateParent(prevOfTarget, target, NULL);
        free(target);
    }
    else if(target->left != NULL && target->right != NULL){//if the target node has both right and left subtree present
        struct BST *maxLeftLeaf = maxIn(target->left);//keeping the address of max data from left branch of target node
        int dataToSwap = maxLeftLeaf->data;//extracting the data value of max from left branch of target
        delete(maxLeftLeaf->data, target);//deleteing the node holding max data from left branch of target node
        target->data = dataToSwap;//putting the value of max data inside target
    }
    else{//if the target node has either left or right subtree present
        struct BST *nextOfTarget = target->left == NULL? target->right : target->left;
        updateParent(prevOfTarget, target, nextOfTarget);
        free(target);
    }
}

void displayInOrder(struct BST* temp) {//to display the tree in incrementing order
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
    delete(5, root);
    printf("\n");
    displayInOrder(root);
    return 0;
}