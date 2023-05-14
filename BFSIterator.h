#pragma once
#include <queue>
#include <unordered_set>
#include "Graph.h"


/**
 * Trieda reprezentujúca iterátor pre preh¾adávanie grafu do šírky.
 */
class BFSIterator
{
public:
    /**
    * Konštruktor triedy BFSIterator
    *
    * @param graph graf, ktorý bude iterovaný pomocou BFS
    */
    explicit BFSIterator(Graph& graph);
    /**
     * Metóda pre resetovanie stavu iterátora
     */
    void Reset();
    /**
    * Metóda pre zistenie, èi iterátor dosiahol koniec
    *
    * @return true, ak je iterátor na konci, inak false
     */
    bool IsEnd();
    /**
    * Metóda pre získanie aktuálneho k¾úèa (vrcholu) iterátora
    *
    * @return aktuálny k¾úè (vrchol)
    */
    int CurrentKey();
    /**
    * Metóda pre posunutie iterátora na ïalší vrchol
    */
    void Next();
    /**
    * Metóda pre výpis poradia preh¾adávania BFS
    */
    void PrintBFSOrder();

private:
    /**
    * Graf, ktorý bude iterovaný pomocou BFS
    */ 
    Graph* graph;
    /**
    * Fronta pre BFS
    */
    std::queue<int> queue;
    /**
    * Množina pre uchovávanie navštívených vrcholov
    */
    std::unordered_set<int> visited; 
    /**
    * Mapa pre uchovávanie krokov preh¾adávania pre každý vrchol
    */
    std::map<int, int> steps; 
    /**
    * Pole pre uchovávanie poradia preh¾adávania BFS
    */
    std::vector<int> bfsOrder; 
};

