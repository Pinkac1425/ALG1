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
* T��da Graph p�edstavuje neorientovan� graf s celo��seln�mi vrcholy a hranami. 
* Konstruktor t��dy Graph p�ij�m� cestu k souboru, kter� obsahuje definici grafu.
* Graf je reprezentov�n pomoc� zoznamu sousednosti, kter� ur�uje vztah mezi vrcholy a jejich sousedy.
*/
class Graph {
private:
    /*
    * brief Pomocn� met�da na pridanie hrany do zoznamu susednosti.
    * 
    * @param from Vrchol, z ktor�ho hrana vych�dza.
    * 
    * @param to Vrchol, do ktor�ho hrana vstupuje.
    */
    void addEdge(int from, int to); 
public:
    /**
    * brief Kon�truktor triedy Graph.
    *
    * param path Cesta k s�boru s defin�ciou grafu.
    */
    explicit Graph(const std::string& path);
    /**
     * brief Met�da pre z�skanie zoznamu susedov dan�ho vrcholu.
     *
     * @param vertex Vrchol, pre ktor� chceme z�ska� zoznam susedov.
     *
     * @return Zoznam susedov vrcholu vertex.
     */
    std::vector<int> GetNeighbors(int vertex);
    /**
     * @brief Met�da pre z�skanie vrcholu s najni���m ��slom v grafe a jeho susedov.
     *
     * @return Vrchol s najni���m ��slom v grafe a jeho zoznam susedov.
     */
    std::pair<int, std::vector<int>> getLowestNode();
    /**
    * brief Met�da pre v�pis grafu.
    */
    void printGraph();
    /**
    * brief zoznam susednosti grafu, ktor� reprezentuje rel�ciu medzi vrcholmi grafu a ich susedmi. 
    * 
    */
    std::unordered_map<int, std::vector<int>> adjacencyList;
};
#endif
