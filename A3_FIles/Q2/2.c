#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct treeNode {
    int key;
    struct treeNode *left;
    struct treeNode *right;
};

typedef struct treeNode treeNode;

treeNode * Insert(treeNode * currentNode, int key) {
    if (currentNode == NULL) {
        treeNode * newNode = (treeNode *) malloc(sizeof(treeNode));
        newNode -> key = key;
        newNode -> left = NULL;
        newNode -> right = NULL;
        return newNode;
    }
    if (key > (currentNode -> key)) {
        currentNode -> right = Insert(currentNode -> right, key);
    }
    else if (key < (currentNode -> key)) {
        currentNode -> left = Insert(currentNode -> left, key);
    }
    return currentNode;
}

void Print(treeNode *currentNode){
    if(currentNode ==NULL){
        return;
    }
    Print(currentNode->left);
    printf("%d ", currentNode->key);
    Print(currentNode->right);
}

treeNode * FindMin(treeNode *currentNode) {
    if(currentNode == NULL){
        return NULL;
    }
    else if(currentNode -> left == NULL){
        return currentNode;
    }
    else{
        return FindMin(currentNode -> left);
    }
}

treeNode * FindMax(treeNode *currentNode) {
    if(currentNode == NULL){
        return NULL;
    }
    else if(currentNode -> right == NULL){
        return currentNode;
    }
    else{
        return FindMax(currentNode -> right);
    }
}

treeNode * Find(treeNode * currentNode, int key) {
    if(currentNode == NULL){
        return NULL;
    }
    else if(currentNode -> key == key){
        return currentNode;
    }
    else if(key > currentNode -> key){
        return Find(currentNode -> right, key);
    }
    else{
        return Find(currentNode -> left, key);
    }
}

int main() {
    treeNode *root = NULL;

    char command[30];
    int value;
    scanf("%s", command);
    while (strcmp(command, "END") != 0) {
        if (strcmp(command, "INSERT") == 0) {
            scanf("%d", &value);
            root = Insert(root, value);
        }
        else if (strcmp(command, "FIND") == 0) {
            scanf("%d", &value);
            treeNode * temp;
            temp = Find(root, value);
            if (temp == NULL)
                printf("Element %d not found\n", value);
            else
                printf("Element %d found\n", value);
        }
        else if (strcmp(command, "PRINT") == 0) {
            Print(root);
            putchar('\n');
        }
        else if (strcmp(command, "FINDMIN") == 0) {
            treeNode * temp;
            temp = FindMin(root);
            printf("Minimum element is %d\n", temp -> key);
        }
        else if (strcmp(command, "FINDMAX") == 0) {
            treeNode * temp;
            temp = FindMax(root);
            printf("Maximum element is %d\n", temp -> key);
        }
        scanf("%s", command);
    }
    return 0;
}
