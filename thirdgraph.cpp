#include "thirdgraph.h"


thirdgraph::thirdgraph(std::string s,std::string infectedString) {
    for(int i = 0; i<infectedString.length();i = i + 2){
        infected.push_back(infectedString[i]);
    }
    for(int i = 0; i<s.length();i= i +2){
        auto node = new struct node();;
        nodes.insert({s[i],node});
    }
}




void thirdgraph::addEdge(char source, char destination)
{
    auto node = nodes.at(source);
    auto infectedIterator = std::find(infected.begin(),infected.end(),destination);
    if(infectedIterator == infected.end()){
        node->cleanNeighbours.insert({destination,nodes.at(destination)});
    }
    else{
        node->infectedNeighbours.insert({destination,nodes.at(destination)});
    }
}

/*best case => days < 1 O(1)
 *if days = 1 O(n) with n amount of nodes
 *if days is bigger than one the first loop is O(N) with N the amount of nodes
 *the removing of the elements in the iteratorlist from nodes is O(N-M) with n the number of nodes and M thenumber of possible sources
 *the for loop in the body is worst case O((D-1)*N^2) which becomes O(D*N*M) with D the number of days and N the number of nodes and M the nodes
 *deleted in the last for loop
 *the last loop which checks what nodes are possible sources (in case of a single source) is O(K) with K the size of toDelete
 */
std::vector<char> thirdgraph::searchInfectionStart(int days){
    if(days >= 1){
        std::vector<char> outerRing;
        std::vector<char> toDelete;
        std::vector<char> certainInfected;
        bool certain = true;
        std::vector<std::unordered_map<char, struct node *>::iterator> iteratorList;
        for(auto it =nodes.begin(); it != nodes.end(); ++it){
            if(!it->second->cleanNeighbours.empty()){
                outerRing.push_back(it->first);
                iteratorList.push_back(it);
            }
        }
        for(int l = iteratorList.size()-1; l >= 0 ; l--){
            nodes.erase(iteratorList[l]);
        }
        iteratorList.clear();
        for(int i = 1;i<days;i++){
            for(auto it =nodes.begin(); it != nodes.end(); it++){
                for(char c : outerRing){
                    auto neighborIt = it->second->infectedNeighbours.find(c);
                    if (neighborIt != it->second->infectedNeighbours.end()) {
                        toDelete.push_back(it->first);
                        iteratorList.push_back(it);
                        break;
                    }
                }
            }
            for(int l = iteratorList.size()-1; l >= 0 ; l--){
                nodes.erase(iteratorList[l]);
            }
            iteratorList.clear();
        }
        outerRing.clear();
        for(auto it =nodes.begin(); it != nodes.end(); it++){
            for(char c : toDelete){
                auto neighborIt = it->second->infectedNeighbours.find(c);
                if (neighborIt == it->second->infectedNeighbours.end()) {
                    certain=false;
                    outerRing.push_back(c);
                    break;
                }
                certain = true;
            }
            if(certain){
                certainInfected.push_back(it->first);
            }
        }
        if(!certainInfected.empty()){
            return certainInfected;
        }
        else{
            return outerRing;
        }
    } else{
        return infected;
    }
}
