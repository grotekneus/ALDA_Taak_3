#ifndef GRAPH_H
#define GRAPH_H

#include <qobject.h>
#include <string>
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
signals:
    void matrixCreated(vector<vector<int>> adjacencymatrix,vector<char> infected);
private:
    typedef struct Node{
        bool infected = false;
    }Node;
    vector<vector<int>> adjacencyMatrix;
    vector<vector<int>> infectionMatrix;
    vector<char> infected;

};

#endif // GRAPH_H
