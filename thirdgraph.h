#ifndef THIRDGRAPH_H
#define THIRDGRAPH_H
#include <string>
#include <unordered_map>
#include <vector>




class thirdgraph
{
public:
    struct node{
        std::unordered_map<char,node*> infectedNeighbours;
        std::unordered_map<char,node*> cleanNeighbours;
    };
    typedef struct node node;
    void addEdge(char source, char destination);
    thirdgraph(std::string s, std::string infected);
    std::vector<char> searchInfectionStart(int days);
private:
    std::unordered_map<char,struct node*> nodes;
    std::vector<char> infected;
};

#endif // THIRDGRAPH_H
