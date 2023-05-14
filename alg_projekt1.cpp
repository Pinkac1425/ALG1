#include "Graph.h"
#include "DFSIterator.h"
#include "BFSIterator.h"

int main() {
    Graph graph("graf1.txt");
    graph.printGraph();
    
    std::cout << "BFS: ";
    BFSIterator bfs(graph);
    bfs.Reset();
    while (!bfs.IsEnd())
    {
        bfs.Next();
    }
    bfs.PrintBFSOrder();

    
    DFSIterator dfs(graph);
    while (!dfs.IsEnd()) {
        dfs.Next();
    }
    auto traversalOrder = dfs.PrintDFSOrder();
    std::cout << "DFS:";
    for (int key : traversalOrder) {
        std::cout << " " << key;
    }
    std::cout << std::endl;
    
    


    return 0;
}