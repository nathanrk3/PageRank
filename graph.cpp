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

    return std::vector<int>();
}

void Graph::pageRank(int n) {
    int num_vertices = this->graph.size();
    std::cout << "Number of Vertices:" << num_vertices << std::endl;
    std::map<std::string, double> ranks;
    for(auto it: names_to_id)
    {
        ranks[it.first] = 1.0 / num_vertices;
    }
    std::vector<int> adjacents;




    for (int j = 1; j < n; j++) {
        std::map<std::string, double> temp;
        //for(auto idk : temp)
        //{
          //  idk.second = 0;
        //}
        for (auto iter : names_to_id) {
            std::string name = iter.first;
            int v = iter.second;
            adjacents = getAdjacent(v);
            if(adjacents.size() != 0)
            {
                //double rank = ranks[name] / adjacents.size();
                double rank = 0.0;
                rank = ranks[name] / adjacents.size();
                for (int a: adjacents)
                {
                    temp[id_to_names[a]] += rank;
                }
            }



        }
        ranks = temp;
    }


    for(auto final : ranks)
    {
        std::cout << final.first << " " << std::fixed << std::setprecision(2) << final.second << std::endl;
    }
}