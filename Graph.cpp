#include "Graph.h"
#include <sstream>

void Graph::addEdge(int from, int to) {
    this->adjacencyList[from].push_back(to);
    this->adjacencyList[to].push_back(from);
}

std::vector<int> Graph::GetNeighbors(int vertex) {
    return this->adjacencyList[vertex];
}

Graph::Graph(const std::string& path) {
    // read file at path and store to the adjacency list
    std::ifstream input_file(path);

    if (!input_file) {
        std::cerr << "Error: Unable to open file" << std::endl;
        return;
    }

    int from, to;
    while (input_file >> from >> to) {
        addEdge(from, to);
    }

    std::string line;
    while (std::getline(input_file, line)) {
        std::istringstream is(line);
        int from, to;
        if (is >> from >> to) {
            addEdge(from, to);
        }
    }

    input_file.close();
}

std::pair<int, std::vector<int>> Graph::getLowestNode() {
    int lowest = 0;
    std::vector<int> lowestNeighbors = this->GetNeighbors(0);
    for (auto it = this->adjacencyList.begin(); it != this->adjacencyList.end(); ++it) {
        int key = it->first;
        std::vector<int>& value = it->second;
        if (key < lowest) {
            lowest = key;
            lowestNeighbors = value;
        }
    }
    return std::make_pair(lowest, lowestNeighbors);
}

void Graph::printGraph() {
    for (auto iter = this->adjacencyList.begin(); iter != this->adjacencyList.end(); ++iter) {
        int key = iter->first;
        std::vector<int>& value = iter->second;

        std::cout << "["<<  key << "]" << " -> ";
        for (auto& neighbor : value)
        {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }
}



