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

std::unordered_set<char> secondGraph::findSourcesBFS(const std::unordered_set<char> &infectedNodes, int days)
{
    unordered_set<char> sources;

    for (char infectedNode : infectedNodes) {
        unordered_set<char> visited;
        queue<pair<char, int>> q;
        q.push({infectedNode, 0});

        while (!q.empty()) {
            char node = q.front().first;
            int day = q.front().second;
            q.pop();

            if (day <= days && visited.find(node) == visited.end()) {
                visited.insert(node);

                if (day == days) {
                    sources.insert(node);
                }

                if (day < days) {
                    for (char neighbor : adjacencyList[node]) {
                        q.push({neighbor, day + 1});
                    }
                }
            }
        }
    }

    return sources;
}
