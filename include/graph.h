#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int numVertices;
    int** adjMatrix;
} Graph;

Graph* createGraph(int v);

void addEdge(Graph* graph, int src, int dest);

void removeEdge(Graph* graph, int src, int dest);

void printAdjMatrix(Graph* graph);

void destroyGraph(Graph* graph);

void BFS(Graph* graph, int start);

#endif

