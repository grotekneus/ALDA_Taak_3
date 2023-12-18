#ifndef SECONDGRAPH_H
#define SECONDGRAPH_H

#include <unordered_map>
#include <unordered_set>



class secondGraph
{
public:
    secondGraph();
    void addEdge(char source, char destination);
    std::unordered_set<char> findSourcesBFS(const std::unordered_set<char>& infectedNodes, int days);
private:
    std::unordered_map<char, std::vector<char>> adjacencyList;
};

#endif // SECONDGRAPH_H
