#include<stdio.h>
#include<stdlib.h>
#include"binarytree.h"

bt* createNode(char value){
    bt* tmp_new = (bt*) malloc(sizeof(bt));  //alociere neuen speicher
    if (tmp_new == NULL){          //überprüfe ob alocation erfolgreich
        return 0;
    } 
    tmp_new->val = value;
    tmp_new->a = NULL;
    tmp_new->b = NULL;
    return tmp_new;
}

void traversePreoder(bt* root) {   //should print A, B, D, E, F, G, C
    if(root != NULL){
        printf("%c, ", root->val);
        traversePreoder(root->a);
        traversePreoder(root->b);
    }
    return;
}

void traverseInorder(bt* root) {  //D, B, E, F, G, A, C
    if(root != NULL){
        traverseInorder(root->a);
        printf("%c, ", root->val);
        traverseInorder(root->b);
    }
    return;
}

void traversePostorder(bt* root) { //D, G, F, E, B, C, A
    if(root != NULL){
        traversePostorder(root->a);
        traversePostorder(root->b);
        printf("%c, ", root->val);
    }
    return;
}

int getDepth(bt* root) {
    if(root != NULL){
        int leftDepth = getDepth(root->a);
        int rigthDepth = getDepth(root->b);
        if (leftDepth >= rigthDepth){
            return leftDepth + 1;
        }
        return rigthDepth + 1;
    }
    else{
        return 0;
    }
}

void deleteTree(bt** rootPtr){
    if(rootPtr != NULL){
        bt* root = *rootPtr;
        if(root != NULL){
            deleteTree(&(root->a));
            deleteTree(&(root->b));
            printf("deleting: %c \n", root->val);
            free(*rootPtr);
            *rootPtr = NULL;
        }
    }
    return;
}

int main() {
    bt* root = createNode('A');
    root->a = createNode('B');
    root->b = createNode('C');
    root->a->a = createNode('D');
    root->a->b = createNode('E');
    root->a->b->b = createNode('F');
    root->a->b->b->b = createNode('G');

    traversePreoder(root);
    printf("\n");
    traverseInorder(root);
    printf("\n");
    traversePostorder(root);
    printf("\n");

    int depth = getDepth(root);
    printf("%d \n",depth);

    deleteTree(&root);

    return 1;
}
