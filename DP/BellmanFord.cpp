#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int source, destination, weight;
};
void bellmanFord(vector<Edge> &graph, int vertices, int source)
{
    vector<int> distance(vertices, INT_MAX);
    distance[source] = 0;
    for (int i = 0; i < vertices; i++)
    {
        for (size_t j = 0; j < graph.size(); j++)
        {
            const Edge &e = graph[j];
            if (distance[e.source] != INT_MAX && distance[e.source] + e.weight < distance[e.destination])
            {
                distance[e.destination] = distance[e.source] + e.weight;
            }
        }
    }
    for (size_t j = 0; j < graph.size(); j++)
    {
        const Edge &e = graph[j];
        if (distance[e.source] != INT_MAX && distance[e.source] + e.weight < distance[e.destination])
        {
            cout << "Negative cycle";
        }
    }
    for (int i = 0; i < graph.size(); i++)
    {
        cout << distance[i] << endl;
    }
}
int main()
{
    int v = 6;
    vector<Edge> graph =
        {
            {0, 1, 5},
            {0, 2, 7},
            {1, 2, 3},
            {1, 3, 4},
            {1, 4, 6},
            {3, 4, -1},
            {3, 5, 2},
            {4, 5, -3}};

    bellmanFord(graph, v, 0);
}