#include<stdio.h>
#include<stdlib.h>
#include"binsearchtree.h"

int addNode(bst** root, int value){
    if (*root == NULL){
        *root = (bst*) malloc(sizeof(bst));  //alociere neuen speicher
        if (*root == NULL){          //überprüfe ob alocation erfolgreich
            return 0;
        } 
        (*root)->val = value;
        (*root)->a = NULL;
        (*root)->b = NULL;
    }
    else {
        if((*root)->val > value){
            addNode(&((*root)->a), value);
        }
        if((*root)->val < value){
            addNode(&((*root)->b), value);
        }
        if((*root)->val == value){
            printf("entry already exists");
        }
    }
    return 1;
}

void traversePreoder(bst* root) { 
    if(root != NULL){
        printf("%d, ", root->val);
        traversePreoder(root->a);
        traversePreoder(root->b);
    }
    return;
}

void traverseInorder(bst* root) { 
    if(root != NULL){
        traverseInorder(root->a);
        printf("%d, ", root->val);
        traverseInorder(root->b);
    }
    return;
}

void traversePostorder(bst* root) { 
    if(root != NULL){
        traversePostorder(root->a);
        traversePostorder(root->b);
        printf("%d, ", root->val);
    }
    return;
}

void deleteTree(bst** root){
    if(root != NULL){
        if((*root) != NULL){
            deleteTree(&((*root)->a));
            deleteTree(&((*root)->b));
            printf("deleting: %d \n", (*root)->val);
            free(*root);
            *root = NULL;
        }
    }
    return;
}

int main() {
    bst* root = NULL;
    if (!addNode(&root, 20)){
        return 0;
    }
    if (!addNode(&root, 10)){
        return 0;
    }
    if (!addNode(&root, 5)){
        return 0;
    }
    if (!addNode(&root, 30)){
        return 0;
    }
    if (!addNode(&root, 15)){
        return 0;
    }
    if (!addNode(&root, 25)){
        return 0;
    } 

    traversePreoder(root);
    printf("\n");
    traverseInorder(root);
    printf("\n");
    traversePostorder(root);
    printf("\n");

    deleteTree(&root);

    return 1;
}
