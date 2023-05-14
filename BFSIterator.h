#pragma once
#include <queue>
#include <unordered_set>
#include "Graph.h"


/**
 * Trieda reprezentuj�ca iter�tor pre preh�ad�vanie grafu do ��rky.
 */
class BFSIterator
{
public:
    /**
    * Kon�truktor triedy BFSIterator
    *
    * @param graph graf, ktor� bude iterovan� pomocou BFS
    */
    explicit BFSIterator(Graph& graph);
    /**
     * Met�da pre resetovanie stavu iter�tora
     */
    void Reset();
    /**
    * Met�da pre zistenie, �i iter�tor dosiahol koniec
    *
    * @return true, ak je iter�tor na konci, inak false
     */
    bool IsEnd();
    /**
    * Met�da pre z�skanie aktu�lneho k���a (vrcholu) iter�tora
    *
    * @return aktu�lny k��� (vrchol)
    */
    int CurrentKey();
    /**
    * Met�da pre posunutie iter�tora na �al�� vrchol
    */
    void Next();
    /**
    * Met�da pre v�pis poradia preh�ad�vania BFS
    */
    void PrintBFSOrder();

private:
    /**
    * Graf, ktor� bude iterovan� pomocou BFS
    */ 
    Graph* graph;
    /**
    * Fronta pre BFS
    */
    std::queue<int> queue;
    /**
    * Mno�ina pre uchov�vanie nav�t�ven�ch vrcholov
    */
    std::unordered_set<int> visited; 
    /**
    * Mapa pre uchov�vanie krokov preh�ad�vania pre ka�d� vrchol
    */
    std::map<int, int> steps; 
    /**
    * Pole pre uchov�vanie poradia preh�ad�vania BFS
    */
    std::vector<int> bfsOrder; 
};

