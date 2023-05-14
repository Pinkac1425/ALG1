#pragma once
#include "Graph.h"

#include "DFSIterator.h"

DFSIterator::DFSIterator(Graph& graph) : graph(&graph) {
    Reset();
}

void DFSIterator::Reset() {
    visited.clear();
    stack = std::stack<int>();
    visitedNodes.clear();
    auto node = graph->getLowestNode();
    visited.insert(node.first);
    stack.push(node.first);
}

bool DFSIterator::IsEnd() {
    return stack.empty();
}

int DFSIterator::CurrentKey() {
    return stack.top();
}

void DFSIterator::Next() {
    int current = stack.top();
    stack.pop();
    visitedNodes.push_back(current);
    std::vector<int> neighbors = graph->GetNeighbors(current);
    for (int i = neighbors.size() - 1; i >= 0; i--) {
        int neighbor = neighbors[i];
        if (visited.find(neighbor) == visited.end()) {
            visited.insert(neighbor);
            stack.push(neighbor);
        }
    }
}

std::vector<int> DFSIterator::PrintDFSOrder() {
    return visitedNodes;
}