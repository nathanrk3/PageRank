//
// Created by natek on 7/13/2024.
//

#ifndef PAGERANK_GRAPH_H
#define PAGERANK_GRAPH_H
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
class Graph
{
private:
    int id = 0;
    std::map<int, std::vector<int>> graph;
    std::map<int, std::string> id_to_names;
    std::map<std::string, int> names_to_id;

public:


    int V(); // number of vertices
    void insertEdge(std::string from, std::string to);
    std::vector<int> getAdjacent(int v);
    void pageRank(int n);



};

#endif //PAGERANK_GRAPH_H
