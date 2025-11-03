/**
 * FILE: DIJKSTRA.C
 * 
 * THIS FILE  CONTAINS EMPTY / DO-NOTHING IMPLEMENTATIONS
 * FOR THE FUNCTIONS REQUIRED OF DIJKSTRA'S ALGORITHM 
 *
 * DO NOT RENAME THESE FUNCTIONS OR CHANGE THEIR RETURN
 * TYPES OR INPUT PARAMETERS.
 *
 * YOU NEED TO COMPLETE THE IMPLEMENTATION OF THESE
 * FUNCTIONS. 
 *
 * THESE FUNCTIONS RECEIVE INPUT PARAMETERS THAT WILL
 * PROVIDE THEM WITH THE INFORMATION THAT THEY REQUIRE. 
 *
 * THE FUNCTIONS RETURN VALUES TO REPRESENT SUCCESS, ERROR,
 * OR, IN SOME CASES, DATA THAT HAS TO BE RETURNED. THE CALLER 
 * OF THESE FUNCTIONS WILL EXPECT TO RECEIVE THESE RETURN VALUES 
 * IN ORDER TO VERIFY THE OUTCOME OF THE FUNCTION CALL. 
 *
 * IF THERE ARE ANY FUNCTIONS THAT YOU DON'T HAVE TIME TO 
 * IMPLEMENT, PLEASE LEAVE THE EMPTY / DO-NOTHING IMPLEMENTATION
 * FOR THEM IN THIS FILE, OTHERWISE YOUR PROGRAM WON'T COMPILE
 * WHEN IT IS FED INTO OUR TESTER PROGRAM.
 * 
 */

/** 
 * ### INCLUDES
 */
#include <stddef.h>
#include <stdio.h>
#include "adj_matrix.h" // provides the definition of the 'Adjacency Matrix' struct which is required for one of the functions below
#include "dijkstra.h"   // provides the definition of structs and functions for the Dijkstra implementation

/** #### FUNCTION IMPLEMENTATIONS ## */

/**
 * This function should perform the Dijkstra algorithm. It expects to receive a 
 * ready-made graph to work with in the form of an AdjacencyMatrix. It 
 * also expects to receive an empty DijkstraTable which will be pre-initialised and 
 * ready to use. It also expects to receive the starting node on the graph to commence 
 * the algorithm from. 
 * 
 * This function should implement the algorithm, running it on the graph 
 * provided and updating the DijkstraTable with the outcome. After the function 
 * is called, the DijkstraTable will be inspected to determine whether the 
 * algorithm has been completed successfully. 
 * 
 * The function should return SUCCESS or a relevant error code.
 */
//variable is required to be global for recurrancy
int count = 0;
int runDijsktraAlgorithm(AdjacencyMatrix *pMatrix, DijkstraTable *pTable, int startNode)
{

    //Check if inputs are valid, if not return error message
    if (pMatrix == NULL){
        return INVALID_INPUT_PARAMETER;
    }

    //initialise required variables
    int minimumDistance = VERY_LARGE_NUMBER;
    int newDistance;
    int tempNode;
    bool found = false;

    //mark current node as visited
    pTable->table[startNode].visited = true;
    //if it is the source node, mark distance as 0
    if (pTable->table[startNode].predecessor < 0){
        pTable->table[startNode].distance = 0;
    }

    //for each possible edge on the current node
    for (int i=0; i<NUMBER_OF_VERTICES; i++){
        //check if either the node exists and hasnt been visited OR if the node exists and the distance to it is shorter than the current recorded shortest distance to the node
        if ((pMatrix->matrix[startNode][i] != 0 && !pTable->table[i].visited) || (pMatrix->matrix[startNode][i] != 0 && pMatrix->matrix[startNode][i] < pTable->table[i].distance)){
            //if current edge is shorter than any other edge found
            if (pMatrix->matrix[startNode][i] < minimumDistance){
                //mark current edge distance as the shortest found
                minimumDistance = pMatrix->matrix[startNode][i];
                //if the current node ISN'T the source node
                if (pTable->table[startNode].predecessor >= 0){
                    //add the distance of the previous node from the source node to the current distance
                    minimumDistance = minimumDistance + pMatrix->matrix[pTable->table[startNode].predecessor][startNode];
                }
                //note the node found
                tempNode = i;
                //mark found as true
                found = true;
            }
        }
    }


    //if found is true, mark the minimum distance found to the found node, and mark its predecessor as the current node.
    //then re-run the function with the new node as the starting node
    if (found){
        pTable->table[tempNode].distance = minimumDistance;
        pTable->table[tempNode].predecessor = startNode;
        runDijsktraAlgorithm(pMatrix, pTable, tempNode);
    }
    
    //if the current node is the source node AND this hasnt been triggered yet
    if (pTable->table[startNode].predecessor < 0 && count == 0){
        //make sure this wont trigger again
        count++;
        //re-run the function with the source node again to ensure quickest paths have been found
        runDijsktraAlgorithm(pMatrix, pTable, startNode);
    }

    return SUCCESS;
    
}


/**
 * This function should determine the shortest path that exists on a graph 
 * from a given starting node (nodeFrom) to a given end node (nodeTo). 
 * The function expects to receive a pre-populated DijkstraTable which already 
 * contains the outcome of running the Dijkstra algorithm on a graph. It will 
 * also be provided with an array (pathFound) into which the shortest path should 
 * be recorded. The path should be recorded in reverse order; showing, from the 
 * end node, the predecessors that lead us there from the start node. 
 * For example, if the shortest path on graph from node 2 to node 8 was found 
 * to be 2 -> 4 -> 5 -> 8. The content that would be recorded in the ‘pathFound’ 
 * variable would be as follows: [8][5][4][2]. I.e., it shows the relevant nodes 
 * in the path, in reverse order. This includes the start and end node too. After the 
 * function is called, the 'pathFound' will be inspected to determine whether the 
 * algorithm has been completed successfully. 
 * 
 * The function should return SUCCESS or a relevant error code.
 */
int getShortestPathFrom(DijkstraTable *pTable, int nodeFrom, int nodeTo, int pathFound[])
{
    // void casts to prevent 'unused variable warning'
    // remove the following lines of code when you have 
    // implemented the function yourself
    (void)pTable;
    (void)nodeFrom;
    (void)nodeTo;
    (void)pathFound;

    // returning NOT_IMPLEMENTED until your own implementation provided
    return NOT_IMPLEMENTED;
}