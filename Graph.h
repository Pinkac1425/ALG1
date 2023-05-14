// Graph.h

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <queue>
#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;
/**
* Tøída Graph pøedstavuje neorientovanı graf s celoèíselnımi vrcholy a hranami. 
* Konstruktor tøídy Graph pøijímá cestu k souboru, kterı obsahuje definici grafu.
* Graf je reprezentován pomocí zoznamu sousednosti, kterı urèuje vztah mezi vrcholy a jejich sousedy.
*/
class Graph {
private:
    /*
    * brief Pomocná metóda na pridanie hrany do zoznamu susednosti.
    * 
    * @param from Vrchol, z ktorého hrana vychádza.
    * 
    * @param to Vrchol, do ktorého hrana vstupuje.
    */
    void addEdge(int from, int to); 
public:
    /**
    * brief Konštruktor triedy Graph.
    *
    * param path Cesta k súboru s definíciou grafu.
    */
    explicit Graph(const std::string& path);
    /**
     * brief Metóda pre získanie zoznamu susedov daného vrcholu.
     *
     * @param vertex Vrchol, pre ktorı chceme získa zoznam susedov.
     *
     * @return Zoznam susedov vrcholu vertex.
     */
    std::vector<int> GetNeighbors(int vertex);
    /**
     * @brief Metóda pre získanie vrcholu s najniším èíslom v grafe a jeho susedov.
     *
     * @return Vrchol s najniším èíslom v grafe a jeho zoznam susedov.
     */
    std::pair<int, std::vector<int>> getLowestNode();
    /**
    * brief Metóda pre vıpis grafu.
    */
    void printGraph();
    /**
    * brief zoznam susednosti grafu, ktorı reprezentuje reláciu medzi vrcholmi grafu a ich susedmi. 
    * 
    */
    std::unordered_map<int, std::vector<int>> adjacencyList;
};
#endif
