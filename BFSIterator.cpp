#include "BFSIterator.h"
BFSIterator::BFSIterator(Graph& graph)
    : graph(&graph)
{
}

void BFSIterator::Reset()
{
    queue = std::queue<int>();
    visited = std::unordered_set<int>();
    steps.clear();
    bfsOrder.clear();  // Resetujeme aj pole s poradím preh¾adávania
    queue.push(graph->getLowestNode().first);
    visited.insert(queue.front());
    steps[queue.front()] = 0;
}

bool BFSIterator::IsEnd()
{
    return queue.empty();
}

int BFSIterator::CurrentKey()
{
    return queue.front();
}

void BFSIterator::Next()
{
    int current = queue.front();
    queue.pop();
    bfsOrder.push_back(current);  // Ukladáme aktuálny vrchol do po¾a s poradím preh¾adávania
    for (auto& neighbor : graph->GetNeighbors(current))
    {
        if (visited.find(neighbor) == visited.end())
        {
            visited.insert(neighbor);
            queue.push(neighbor);
            steps[neighbor] = steps[current] + 1;
        }
    }
}

void BFSIterator::PrintBFSOrder()
{
    for (auto& vertex : bfsOrder)  // Vypíšeme vrcholy v poradí preh¾adávania
    {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;
}
