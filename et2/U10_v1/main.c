#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void addNode(node** nodeList, char Name) {
	if (nodeList == NULL) {
		printf("Invalid pointer given!\n");
		return;
	}
	//if the node list is empty or we have reached the end of the list,
	//we append the new element and leave the function
	if (*nodeList == NULL) {
		node* newNode = (node*) malloc(sizeof(node));
		if (newNode == NULL) {
			printf("Could not create node!");
			return;
		}
		newNode->edges = NULL;
		newNode->name = Name;
		newNode->visited = 0;
		newNode->next = NULL;
		*nodeList = newNode;
		return;
	}
	//check whether a node with name Name already exists
	if ((*nodeList)->name != Name) {
		//this is a recursive method to cycle through the node list
		//we might as well solve it iteratively using a pointer pointing
		//to the current element.
		addNode(&((*nodeList)->next), Name);
	} else {
		printf("Node %c already exists!\n", Name);
		return;
	}
}

/*
 * addEdgeUnidirectional adds an edge from start nameStartNode to
 * nameEndNode with distance distance.
 */
void addEdgeUnidirectional(node** nodeList, char nameStartNode, char nameEndNode, unsigned int distance) {
	/* when adding a new edge, we need to make sure a few things:
	 * - we need to check whether the start node exists
	 * - we need to make sure that the end node exists
	 * - we want to make sure that there isn't another edge
	 *   from start node to end node yet (this isn't necessarily
	 *   forbidden as you know from the lecture. However,
	 *   we want to keep things easy within this exercise)
	 *
	*/
	if (nodeList == NULL) {
		printf("Invalid pointer given!\n");
		return;
	}
	if (*nodeList == NULL) {
		printf("Invalid pointer given!\n");
		return;
	}

	//find the start and end node
	node* currentN = *nodeList;
	node* A_node = NULL;
	node* B_node = NULL;
	while(currentN != NULL){
		if(currentN->name == nameStartNode){
			A_node = currentN;
		}
		if(currentN->name == nameEndNode){
			B_node = currentN;
		}
		currentN = currentN->next;
	}

	//check if nodes have been found
	if(A_node == NULL || B_node == NULL){
		printf("Nodes not found!\n");
		return;
	}
	else{
		edge* currentE = A_node->edges;
		//check if edge already exists
		if (currentE != NULL) {
			while(currentE->next != NULL){
				if(currentE->toNode == B_node){
					printf("Edge already exists\n");
					return;
				}
				currentE = currentE->next;
			}
		}

		//add new edge
		edge* new_edge = (edge*) malloc(sizeof(edge));
		if(new_edge == NULL){
			printf("Could not create node!");
			return;
		}
		new_edge->toNode = B_node;
		new_edge->distance = distance;
		new_edge->next = A_node->edges;
		A_node->edges = new_edge;
	}
	
	return;
}

/*
 * Adding a bidirectional edge is facilitated by calling
 * addEdgeUnidirectional twice (once for each direction)
 */
void addEdge(node** nodeList, char nameStartNode, char nameEndNode,
		unsigned int distance) {
	addEdgeUnidirectional(nodeList, nameStartNode, nameEndNode, distance);
	addEdgeUnidirectional(nodeList, nameEndNode, nameStartNode, distance);
}

void printGraph(node* nodeList) {
	if (nodeList == NULL) {
		return;
	}
	printf("%c\t", nodeList->name);
	edge* current = nodeList->edges;
	while (current != NULL) {
		printf("-- %c|%d\t", current->toNode->name, current->distance);
		current = current->next;
	}
	printf("\n");
	printGraph(nodeList->next);
}

/*
 * This function is just the full traversal of the graph
 * by the depth-first search algorithm
 */
void depthSearch(node* nodeList, char startNode) {
	if (nodeList == NULL) {
		printf("Invalid pointer given!\n");
		return;
	} 

	//find the address of start
	node* currentN = nodeList;
	node* A_node = NULL;
	while(currentN != NULL){
		if(currentN->name == startNode){
			A_node = currentN;
		}
		currentN = currentN->next;
	}
	//check if node has been found
	if(A_node == NULL){
		return;
	}

	printf("%c\t", startNode);
	
	A_node->visited = 1;
	edge* currentE = A_node->edges;
	while(currentE != NULL){
		if(!(currentE->toNode->visited)){
			depthSearch(nodeList, currentE->toNode->name);
		}
		currentE = currentE->next;
	}
}

/* findByDepthSearch detects, whether node candidate can
 * be reached by node startNode by exploiting the depth-first search algorithm
 */
int findByDepthSearch(node* nodeList, char startNode, char candidate) {
	int candidate_found = 0;
	if (nodeList == NULL) {
		printf("Invalid pointer given!\n");
		return -1;
	} 

	if (startNode == candidate){
		return 1;
	}

	//find the address of start
	node* currentN = nodeList;
	node* A_node = NULL;
	while(currentN != NULL){
		if(currentN->name == startNode){
			A_node = currentN;
		}
		currentN = currentN->next;
	}
	//check if node has been found
	if(A_node == NULL){
		return 0;
	}

	A_node->visited = 1;
	edge* currentE = A_node->edges;
	while(currentE != NULL){
		if(!(currentE->toNode->visited)){
			candidate_found = candidate_found + findByDepthSearch(nodeList, currentE->toNode->name, candidate);
		}
		currentE = currentE->next;
	}
	return candidate_found;
}

/*
 * printVisitedNodes prints out all nodes that are marked
 * as visited
 */
void printVisitedNodes(node* nodeList) {
	if (nodeList != NULL) {
		if (nodeList->visited == 1) {
			printf("%c\t", nodeList->name);
		}
		printVisitedNodes(nodeList->next);
	}
}

/*
 * resetVisitedNodes resets the visited mark for all nodes
 */
void resetVisitedNodes(node* nodeList) {
	if (nodeList != NULL) {
		nodeList->visited = 0;
		resetVisitedNodes(nodeList->next);
	}
}

/*
 * freeAdjacencyMatrix frees the memory from the adjacency matrix
 */
void freeAdjacencyMatrix(adM** myAdM) {
	if (*myAdM != NULL) {
		free((*myAdM)->names);
		if ((*myAdM)->A != NULL) {
			for (unsigned int i = 0; i < (*myAdM)->numberOfNodes; i++) {
				free((*myAdM)->A[i]);
			}
			free((*myAdM)->A);
		}
		free((*myAdM));
		*myAdM = NULL;
	}
}

/*
 * given a graph structured as a list of nodes, createAdjacencyMatrix
 * builds an adjacency matrix representation of the graph
 */
adM* createAdjacencyMatrix(node* nodeList) {
	if (nodeList == NULL) {
		printf("Invalid pointer given!\n");
		return NULL;
	} 

	//anzahl der numberOfNodes und names suchen
	int numberOfNodes = 0;
	node* currentN = nodeList;
	while(currentN != NULL){
		numberOfNodes++;
		currentN = currentN->next;
	}

	adM* AdjacencyMatrix = (adM*) malloc(sizeof(adM));
	AdjacencyMatrix->numberOfNodes = numberOfNodes;
	AdjacencyMatrix->names = (char*) malloc(numberOfNodes * sizeof(char));
	AdjacencyMatrix->A = (unsigned int**) malloc(numberOfNodes * sizeof(unsigned int*));
	currentN = nodeList;
	for (int i = 0; i < numberOfNodes; i++) {
		AdjacencyMatrix->A[i] = (unsigned int*) calloc(numberOfNodes, sizeof(unsigned int));
		AdjacencyMatrix->names[i] = currentN->name;
		currentN = currentN->next;
	}

	currentN = nodeList;
	edge* currentE;
	for (int i = 0; i < numberOfNodes; i++) {
		currentE = currentN->edges;
		while (currentE != NULL){
			for (int j = 0; j < numberOfNodes; j++){
				if (currentE->toNode->name == AdjacencyMatrix->names[j]){
					AdjacencyMatrix->A[i][j] = currentE->distance;
				}
			} 
			currentE = currentE->next;
		}
		currentN = currentN->next;
	}

	return AdjacencyMatrix;
}

/*
 * printAdjacencyMatrix prints the contents of the AdjacencyMatrix
 */
void printAdjacencyMatrix(adM* myAdM) {
	if (myAdM == NULL) {
		printf("No Adjacency Matrix given!\n");
		return;
	}
	if (myAdM->A == NULL) {
		printf("Empty Matrix given!\n");
		return;
	}

	printf("\t");
	for (unsigned int i = 0; i < myAdM->numberOfNodes; i++) {
		printf("%c\t", myAdM->names[i]);
	}
	printf("\n");
	for (unsigned int i = 0; i < myAdM->numberOfNodes; i++) {
		printf("%c\t", myAdM->names[i]);
		for (unsigned int j = 0; j < myAdM->numberOfNodes; j++) {
			printf("%d\t", myAdM->A[i][j]);
		}
		printf("\n");
	}
}
/*
 * freeEdgeList is a helper function, which frees the memory
 * for a edge list of a node. It is called by freeGraph
 */
void freeEdgeList(edge* edgeList) {
	if (edgeList != NULL) {
		freeEdgeList(edgeList->next);
		free(edgeList);
	}
}

/*
 * freeGraph frees the memory allocated for the graph, i.e. for the
 * nodes as well as their corresponding edges
 */
void freeGraph(node** nodeList) {
	if (nodeList == NULL) {
		printf("Invalid pointer given!\n");
		return;
	}
	if (*nodeList != NULL) {
		freeGraph(&((*nodeList)->next));
		freeEdgeList((*nodeList)->edges);
		*nodeList = NULL;
	}
}

int main(void) {
	node* graph = NULL;
	addNode(&graph, 'a');
	addNode(&graph, 'b');
	addNode(&graph, 'c');
	addNode(&graph, 'd');
	addNode(&graph, 'e');
	addNode(&graph, 'f');
	addNode(&graph, 'g');
	addNode(&graph, 'h');
	addNode(&graph, 'i');
	addNode(&graph, 'j');
	addNode(&graph, 'k');
//check whether we handle double creation of nodes:
	addNode(&graph, 'k');

	addEdge(&graph, 'a', 'b', 5);
	addEdge(&graph, 'b', 'c', 1);
	addEdge(&graph, 'c', 'd', 3);
	addEdge(&graph, 'c', 'h', 2);
	addEdge(&graph, 'c', 'i', 3);
	addEdge(&graph, 'f', 'e', 6);
	addEdge(&graph, 'f', 'g', 4);
	addEdge(&graph, 'e', 'g', 1);
	addEdge(&graph, 'g', 'j', 2);
	addEdge(&graph, 'j', 'k', 2);
	//check whether we catch creation of edges between nodes not present:
	addEdge(&graph, 'a', 'z', 2);
	//check whether we catch creation of already existing edges
	addEdge(&graph, 'a', 'b', 2);
	//check, whether circles do work (uncomment this to test, since the exercise did not make clear whether
	//you should handle this
	//addEdge(&graph, 'a', 'a', 7);
	printGraph(graph);

	printf("\nNow traversing graph via depthSearch starting from a\n");
	depthSearch(graph, 'a');
	printf("\n");
	printVisitedNodes(graph);
	printf("\n");
	resetVisitedNodes(graph);

	//check, whether depthSearch catches invalid start node names:
	printf(
			"\nNow traversing graph via depthSearch starting from non-existing node z\n");
	depthSearch(graph, 'z');
	printf("\n");
	printVisitedNodes(graph);
	printf("\n");
	resetVisitedNodes(graph);


	printf("\nNow depth searching for h starting at a:\n");
	printf("%i", findByDepthSearch(graph, 'a', 'h'));
	printf("\n");
	printVisitedNodes(graph);
	printf("\n");
	resetVisitedNodes(graph);

	printf("\nNow depth searching for g starting at a:\n");
	printf("%i", findByDepthSearch(graph, 'a', 'g'));
	printf("\n");
	printVisitedNodes(graph);
	printf("\n");
	resetVisitedNodes(graph);

	printf("\nNow depth searching for z starting at a:\n");
	printf("%i", findByDepthSearch(graph, 'a', 'z'));
	printf("\n");
	printVisitedNodes(graph);
	printf("\n");
	resetVisitedNodes(graph);

	printf("\nNow depth searching for h starting at a:\n");
	printf("%i", findByDepthSearch(graph, 'a', 'h'));
	printf("\n");
	printVisitedNodes(graph);
	printf("\n");
	resetVisitedNodes(graph);

	printf("\n\n");

	adM* myAdM = createAdjacencyMatrix(graph);
	printAdjacencyMatrix(myAdM);

	freeAdjacencyMatrix(&myAdM);
	freeGraph(&graph);
	return EXIT_SUCCESS;
}
