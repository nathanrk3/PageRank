//
// Created by natek on 7/15/2024.
//
#include "graph.h"
#include <iomanip>


void Graph::insertEdge(std::string from, std::string to)
{
    if (names_to_id.find(from) == names_to_id.end()) {
        names_to_id[from] = id;
        id_to_names[id] = from;
        graph[id] = std::vector<int>();
        id++;
    }

    if (names_to_id.find(to) == names_to_id.end()) {
        names_to_id[to] = id;
        id_to_names[id] = to;
        graph[id] = std::vector<int>();
        id++;
    }

    graph[names_to_id[from]].push_back(names_to_id[to]);
}
std::vector<int> Graph::getAdjacent(int v)
{
    if(this->graph.find(v) != graph.end())
        return graph[v];

    return std::vector<int>();//returns empty vector if node doesnt exist
}

void Graph::pageRank(int n) {
    int num_vertices = this->graph.size();
    std::map<std::string, double> ranks;
    for(auto it: names_to_id)
    {
        ranks[it.first] = 1.0 / num_vertices;
    }
    std::vector<int> adjacents;

    // Debug: Print initial ranks
    std::cout << "Initial ranks:" << std::endl;
    std::cout << "Number of Vertices: " << num_vertices << std::endl;
    for (int i = 0; i < num_vertices; i++) {
        std::cout << i << ": " << ranks[i] << std::endl;
    }

    for (int j = 0; j < n; j++) {
        std::vector<double> temp(num_vertices, 0.0);
        for (int i = 0; i < num_vertices; i++) {
            adjacents = getAdjacent(i);
            if(adjacents.size() != 0)
            {
                double rank = ranks[i] / adjacents.size();
                for (int a: adjacents)
                {
                    temp[a] += rank;
                }
            }
            else
            {
                for(int c = 0; c < num_vertices; c++)
                {
                    temp[c] += ranks[i] / num_vertices;
                }
            }


        }
        ranks = temp;
    }

    // Debug: Print final ranks
    std::cout << "Final ranks after " << n << " iterations:" << std::endl;

    for(auto it : id_to_names)
    {
        std::cout << it.second << " " << std::fixed << std::setprecision(2) << ranks[it.first] << std::endl;

    }
}