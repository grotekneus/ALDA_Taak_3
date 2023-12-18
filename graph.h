#ifndef GRAPH_H
#define GRAPH_H

#include <qobject.h>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;




class graph:public QObject
{
    Q_OBJECT
public:
    graph(std::string s);
    void fillMatrixFromString(std::string s);
    void makeInfectionMatrixFromString(std::string s);
    vector<vector<int> > matrixMultiply(const vector<vector<int> > A, const vector<vector<int> > B);
    vector<char> findSource1(int days);
    unordered_set<char> findSourcesBFS(int days);
signals:
    void matrixCreated(vector<vector<int>> adjacencymatrix,vector<char> infected);
private:
    typedef struct Node{
        bool infected = false;
    }Node;
    vector<vector<int>> adjacencyMatrix;
    vector<vector<int>> infectionMatrix;
    unordered_map<char, vector<char>> adjacencyListBFS;
    vector<char> infected;
    vector<char> infectedBFS;

};

#endif // GRAPH_H
