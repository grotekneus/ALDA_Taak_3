#include "graph.h"
#include <iostream>

graph::graph(std::string s) {
    int size = (s.length()+1)/2;
    std::vector<std::vector<int>> initMatrix(size, std::vector<int>(size, 0));
    this->adjacencyMatrix = initMatrix;
    this->infectionMatrix = initMatrix;
}

void graph::fillMatrixFromString(std::string s)
{
    int i = 0;
    while(i<s.length()){
        std::cout <<s[i] - 65 << s[i + 3] - 65;
        this->adjacencyMatrix[s[i + 3] - 65][s[i] - 65] = 1;
        i += 5;
    }
    emit matrixCreated(adjacencyMatrix,infected);
}

void graph::makeInfectionMatrixFromString(std::string s){
    for(int i = 0; i<s.length();i += 2){
        this->infected.push_back(s[i]);
    }
}

vector<char> graph::findSource1(int days)
{
    vector<vector<int>> result1 = adjacencyMatrix;
    vector<vector<int>> result = adjacencyMatrix;
    vector<char> sources;
    for(int i = 0;i<days-1;i++){
        if(i ==  days-3){
            result1 = matrixMultiply(result,adjacencyMatrix);
            result = result1;
        }
        else{
            result = matrixMultiply(result,adjacencyMatrix);
        }
    }
    bool possibleCause = true;
    for(int y = 0;y<infected.size();y++){
        for(int x = 0;x <result.size();x++){
            if(std::find(infected.begin(),infected.end(),(char) x+65) == infected.end()){
                if(result[infected[y]-65][x] != 0){
                    possibleCause = false;
                    break;
                }
            }
            else{
                if(result[infected[y]-65][infected[x]-65] == 0){
                    if(result1[infected[y]-65][infected[x]-65] == 0){
                        possibleCause = false;
                        break;
                    }
                }
            }
        }
        if(possibleCause){
            sources.push_back((char) y+65);
        }
        possibleCause = true;
    }
    return sources;
}

vector<vector<int>> graph::matrixMultiply(const vector<vector<int>> A, const vector<vector<int>> B) {
    int m = A.size();
    int n = A[0].size();
    int p = B[0].size();

    vector<vector<int>> result(m, vector<int>(p, 0));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

