#include "graph.h"
int main() {
    int no_lines, power;

    std::string from, to;

    Graph graph;

    std::cin >> no_lines >> power;

    for(int i = 0; i < no_lines ; i++)
    {

        std::cin >> from >> to;
        graph.insertEdge(from, to);

    }
    graph.pageRank(power);
    return 0;
}
