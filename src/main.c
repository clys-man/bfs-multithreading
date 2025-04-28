#include <graph.h>

int main() {
    Graph* graph = createGraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    BFS(graph, 0);

    destroyGraph(graph);

    return 0;
}
