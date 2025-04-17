#include "graph.h"

Graph* createGraph(int v) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = v;

    graph->adjMatrix = (int**)malloc(v * sizeof(int*));
    for (int i = 0; i < v; i++) {                                                                                                
        graph->adjMatrix[i] = (int*)malloc(v * sizeof(int));

        for (int j = 0; j < v; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    if (src >= graph->numVertices || dest >= graph->numVertices || src < 0 || dest < 0) {
        printf("Erro: Vértice fora do intervalo permitido.\n");
        return;
    }

    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

void removeEdge(Graph* graph, int src, int dest) {
    if (src >= graph->numVertices || dest >= graph->numVertices || src < 0 || dest < 0) {
        printf("Erro: Vértice fora do intervalo permitido.\n");
        return;
    }

    graph->adjMatrix[src][dest] = 0;
    graph->adjMatrix[dest][src] = 0;
}


void printAdjMatrix(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void destroyGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjMatrix[i]);
    }

    free(graph->adjMatrix);
    free(graph);
}

