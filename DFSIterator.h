#include "Graph.h"
#include <stack>
#include <unordered_set>
#include <map>
#include <vector>
#include <iostream>

/**
* Trieda reprezentujúca iterátor pre håbkové preh¾adávanie grafu.
*/
class DFSIterator {
public:
    /**
    * Konštruktor iterátora, vytvára novı iterátor pre danı graf.
    *
    * @param graph graf, ktorı bude iterátor preh¾adáva
    */
    explicit DFSIterator(Graph& graph);
    /**
    * Resetuje iterátor na zaèiatok, pripravenı na preh¾adávanie.
    */
    void Reset();
    /**
    * Kontroluje, èi u bol prejdenı celı graf.
    *
    * @return true, ak u boli prejdené všetky vrcholy, inak false
    */
    bool IsEnd();
    /**
    * Vráti aktuálny vrchol v poradí preh¾adávania.
    *
    * @return aktuálny vrchol v poradí preh¾adávania
    */
    int CurrentKey();
    /**
     * Posunie iterátor na nasledujúci vrchol v poradí preh¾adávania.
     */
    void Next();

    /**
     * Vráti vektor obsahujúci vrcholy grafu v poradí, v akom boli navštívené pri preh¾adávaní.
     *
     * @return vektor vrcholov v poradí, v akom boli navštívené pri preh¾adávaní
     */
    std::vector<int> PrintDFSOrder();
private:
    /**
    * Graf, ktorı bude iterovanı pomocou DFS
    */
    Graph* graph;
    /**
    * zásobník pre ukladanie vrcholov
    */
    std::stack<int> stack;
    /**
    * mnoina u navštívenıch vrcholov
    */
    std::unordered_set<int> visited;
    /**
    * vektor pre ukladanie navštívenıch vrcholov v poradí DFS preh¾adávania
    */
    std::vector<int> visitedNodes;
};