#include "Graph.h"
#include <stack>
#include <unordered_set>
#include <map>
#include <vector>
#include <iostream>

/**
* Trieda reprezentuj�ca iter�tor pre h�bkov� preh�ad�vanie grafu.
*/
class DFSIterator {
public:
    /**
    * Kon�truktor iter�tora, vytv�ra nov� iter�tor pre dan� graf.
    *
    * @param graph graf, ktor� bude iter�tor preh�ad�va�
    */
    explicit DFSIterator(Graph& graph);
    /**
    * Resetuje iter�tor na za�iatok, pripraven� na preh�ad�vanie.
    */
    void Reset();
    /**
    * Kontroluje, �i u� bol prejden� cel� graf.
    *
    * @return true, ak u� boli prejden� v�etky vrcholy, inak false
    */
    bool IsEnd();
    /**
    * Vr�ti aktu�lny vrchol v porad� preh�ad�vania.
    *
    * @return aktu�lny vrchol v porad� preh�ad�vania
    */
    int CurrentKey();
    /**
     * Posunie iter�tor na nasleduj�ci vrchol v porad� preh�ad�vania.
     */
    void Next();

    /**
     * Vr�ti vektor obsahuj�ci vrcholy grafu v porad�, v akom boli nav�t�ven� pri preh�ad�van�.
     *
     * @return vektor vrcholov v porad�, v akom boli nav�t�ven� pri preh�ad�van�
     */
    std::vector<int> PrintDFSOrder();
private:
    /**
    * Graf, ktor� bude iterovan� pomocou DFS
    */
    Graph* graph;
    /**
    * z�sobn�k pre ukladanie vrcholov
    */
    std::stack<int> stack;
    /**
    * mno�ina u� nav�t�ven�ch vrcholov
    */
    std::unordered_set<int> visited;
    /**
    * vektor pre ukladanie nav�t�ven�ch vrcholov v porad� DFS preh�ad�vania
    */
    std::vector<int> visitedNodes;
};