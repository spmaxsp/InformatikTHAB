#include<stdio.h>
#include<stdlib.h>
#include"binsearchtree.h"
#include"queue.h"

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

int addToQueue(queue** myQueue, bst* node) {
    if (node == NULL){
        return 0;
    }
    if (myQueue == NULL){
        return 0;
    }

    queue* tmp_new = (queue*) malloc(sizeof(queue));  //alociere neuen speicher
    if (tmp_new == NULL){          //überprüfe ob alocation erfolgreich
        return 0;
    } 
    tmp_new->pointer = node;
    tmp_new->next = NULL;

    if (*myQueue == NULL) {
        *myQueue = tmp_new;
        return 1;
    }
    else{
        queue* current = *myQueue;     //current ist nun die adresse auf die head zeigt
        while(current->next != NULL){ 
            current = current->next; 
        }
        current->next = tmp_new;
        return 1;
    }
}

bst* removeFromQueue(queue** myQueue) {
    if (myQueue == NULL) {
        return NULL;
    }
    if (*myQueue == NULL) {
        return NULL;
    }
    else{
        queue* current = *myQueue;
        bst* pointertoReturn = current->pointer;
        *myQueue = current->next;
        free(current);
        return pointertoReturn;
    }
}

void printQueue(queue* myQueue){
    if (myQueue == NULL){    
        return;
    }
    else { 
        printf("%d ", myQueue->pointer);
        while(myQueue->next != NULL){
            myQueue = myQueue->next; 
            printf("%d ", myQueue->pointer);
        }
    }
    return;
}

int findByBreadthFirstSearch(bst* root, int value){
    queue* head = NULL;
    if(root == NULL){
        return 0;
    }
    bst* searchadress = root;
    while(searchadress != NULL){
        printf("checking node: %d ", searchadress->val);
        printf("at: %d ", searchadress);
        printf("queue: [");
        printQueue(head);
        printf("]\n");
        if (searchadress->val == value){
            while (removeFromQueue(&head) != NULL){}
            return 1;
        }
        addToQueue(&head, searchadress->a);
        addToQueue(&head, searchadress->b);
        searchadress = removeFromQueue(&head);
    }
    return 0;
}

int findByDepthFirstSearch(bst* root, int value){
    if(root == NULL){
        return 0;
    }
    printf("checking node: %d ", root->val);
    printf("at: %d \n", root);
    if (root->val == value){
        return 1;
    }
    else{
        if(findByDepthFirstSearch(root->a, value)) {
            return 1;
        }
        if(findByDepthFirstSearch(root->b, value)) {
            return 1;
        }
    } 
}

int find(bst* root, int value){
    if(root == NULL){
        return 0;
    }
    else{
        printf("checking node: %d ", root->val);
        printf("at: %d \n", root);
        if(root->val > value){
            return find(root->a, value);
        }
        if(root->val < value){
            return find(root->b, value);
        }
        if(root->val == value){
            return 1;
        }
    } 
}

int findAtDepth(bst* root, int value){
    if(root == NULL){
        return 0;
    }

    else{
        printf("checking node: %d ", root->val);
        printf("at: %d \n", root);
        if(root->val == value){
            return 1;
        }
        else{
            int depth;
            if(root->val > value){
                depth = findAtDepth(root->a, value);
            }
            else if(root->val < value){
                depth = findAtDepth(root->b, value);
            }        
            
            if (depth != 0 ) {return (depth + 1);} 
            else {return 0;}
        }
    } 
}

void printSorted(bst* root) { 
    if(root != NULL){
        printSorted(root->a);
        printf("%d, ", root->val);
        printSorted(root->b);
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
    int res;

    printf(">>>creating binary searchtree:\n");
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
    printf("\n");

    printf(">>>printing sorted binary searchtree:\n");
    printSorted(root);
    printf("\n");
    printf("\n");

    //find
    printf(">>>searching sorted searchtree for 18:\n");
    res = find(root, 18);
    printf("find returned: ");
    if (res) {printf("true \n");} else {printf("false \n");}
    printf("\n");

    printf(">>>searching sorted searchtree for 15:\n");
    res = find(root, 15);
    printf("find returned: ");
    if (res) {printf("true \n");} else {printf("false \n");}
    printf("\n");

    //findAtDepth
    printf(">>>finding depht in sorted searchtree for 18:\n");
    res = findAtDepth(root, 18);
    printf("findAtDepth returned: ");
    if (!res) {printf("false \n");} else {printf("depht of: %i \n",res);}
    printf("\n");

    printf(">>>finding depht in sorted searchtree for 20:\n");
    res = findAtDepth(root, 20);
    printf("findAtDepth returned: ");
    if (!res) {printf("false \n");} else {printf("depht of: %i \n",res);}
    printf("\n");

    printf(">>>finding depht in sorted searchtree for 15:\n");
    res = findAtDepth(root, 15);
    printf("findAtDepth returned: ");
    if (!res) {printf("false \n");} else {printf("depht of: %i \n",res);}
    printf("\n");   

    //findByDepthFirstSearch
    printf(">>>searching by depth first search for 18:\n");
    res = findByDepthFirstSearch(root, 18);
    printf("findByDepthFirstSearch returned: ");
    if (res) {printf("true \n");} else {printf("false \n");}
    printf("\n");

    printf(">>>searching by depth first search for 15:\n");
    res = findByDepthFirstSearch(root, 15);
    printf("findByDepthFirstSearch returned: ");
    if (res) {printf("true \n");} else {printf("false \n");}
    printf("\n");

    //findByBreadthFirstSearch
    printf(">>>searching by breadth first search for 18:\n");
    res = findByBreadthFirstSearch(root, 18);
    printf("findByBreadthFirstSearch returned: ");
    if (res) {printf("true \n");} else {printf("false \n");}
    printf("\n");

    printf(">>>searching by breadth first search for 15:\n");
    res = findByBreadthFirstSearch(root, 15);
    printf("findByBreadthFirstSearch returned: ");
    if (res) {printf("true \n");} else {printf("false \n");}
    printf("\n");

    printf(">>>deleting tree:\n");
    deleteTree(&root);

    return 1;
}
