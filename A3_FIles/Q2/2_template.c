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
        // Case 1: If the tree rooted at currentNode is empty
        // To be implemented
    }
    if (key > (currentNode -> key)) {
        // Case 2: If the tree rooted at currentNode is not empty and if the given key is greater than currentNode -> key
        // To be implemented
    }
    else if (key < (currentNode -> key)) {
        // Case 3: If the tree rooted at currentNode is not empty and if the given key is smaller than currentNode -> key
        // To be implemented
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
    // To be implemented
}

treeNode * FindMax(treeNode *currentNode) {
    // To be implemented
}

treeNode * Find(treeNode * currentNode, int key) {
    // To be implemented
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
}
