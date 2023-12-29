#include "secondgraph.h"
#include <queue>

using namespace std;

secondGraph::secondGraph()
{

}

void secondGraph::addEdge(char source, char destination)
{
    if(this->adjacencyList.find(source) != this->adjacencyList.end()){
        this->adjacencyList[source].push_back(destination);
    }
    else{
        std::vector<char> neighbourList = {destination};
        this->adjacencyList.insert({source, neighbourList});
    }
}

/*
 * De tijdscomplexiteit van het Breadth First Search algoritme is:
 *   - in de for loop worden alle infected vertices overlopen, we noemen deze V
 *   - binnen de for loop worden alle buren van de vertices bezocht,
 *     het doorlopen van alle buren heeft een tijdscomplexiteit van O(E)
 *     E is het aantel edges in de graaf
 *   - het markeren van een vertice als visited heeft een tijdscomplexiteit van O(1),
 *     omdat we werken met een unordered map.
 * De totale tijdscomplexiteit van dit algoritme is dan O(V + E + 1) wat vereenvoudigd naar O(V + E),
 *   met V het aantal infected vertices en E het aantal edges in de graaf.
*/
std::unordered_set<char> secondGraph::findSourcesBFS(const std::unordered_set<char> &infectedNodes, int days)
{
    unordered_set<char> sources;
    unordered_set<char> visited;
    queue<pair<char, int>> q;

    for (char infectedNode : infectedNodes) {
        q.push({infectedNode, 0});

        while (!q.empty()) {
            char node = q.front().first;
            int day = q.front().second;
            q.pop();

            if (day <= days && visited.find(node) == visited.end()) {
                visited.insert(node);

                if (day < days) {
                    for (char neighbor : adjacencyList[node]) {
                        q.push({neighbor, day + 1});
                    }
                }
                if (day == days) {
                    sources.insert(infectedNode);
                }
            }
        }
    }


    return sources;
}
