#include <bits/stdc++.h>
using namespace std;
#define V 5 // Number of vertices in the graph

// Function to find the vertex with the minimum key value that is not yet included in the MST
int minKey(vector<int> &key, vector<bool> &msSet)
{
    int min = INT_MAX; // Initialize minimum value
    int min_index;

    // Traverse all vertices to find the vertex with the minimum key value
    for (int v = 0; v < V; v++)
    {
        // If the vertex is not yet included in the MST and its key value is smaller than the current minimum
        if (msSet[v] == false && key[v] < min)
        {
            min = key[v];  // Update the minimum value
            min_index = v; // Store the index of the vertex
        }
    }
    return min_index; // Return the index of the vertex with the minimum key value
}

// Function to implement Prim's algorithm to find the Minimum Spanning Tree (MST)
void primMST(vector<vector<int>> &graph)
{
    // Array to store the parent of each vertex in the MST
    vector<int> parent(V);

    // Key values used to pick the minimum weight edge in the cut
    vector<int> key(V);

    // To represent the set of vertices included in the MST
    vector<bool> msSet(V);

    // Initialize all keys as infinite and msSet[] as false
    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX; // Infinite value to indicate the vertex is not yet processed
        msSet[i] = false; // Vertex is not yet included in the MST
    }

    // Always include the first vertex in the MST
    key[0] = 0;     // Make key of the first vertex 0 so that it is picked first
    parent[0] = -1; // First node is always the root of the MST

    // The MST will have V-1 edges
    for (int count = 0; count < V - 1; count++)
    {
        // Step 1: Pick the vertex with the minimum key value that is not yet included in the MST
        int u = minKey(key, msSet);

        // Include the picked vertex in the MST
        msSet[u] = true;

        // Step 2: Update key values and parent indices of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++)
        {
            // Update the key and parent if:
            // - There is an edge from u to v (graph[u][v] > 0)
            // - v is not yet included in the MST (msSet[v] == false)
            // - The weight of the edge u-v is smaller than the current key value of v
            if (graph[u][v] && msSet[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u;        // Set u as the parent of v
                key[v] = graph[u][v]; // Update the key value of v
            }
        }
    }

    // Print the edges of the MST and their weights
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) // Start from 1 because 0 is the root
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << " \n";
}

int main()
{
    // Graph represented as an adjacency matrix
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}};

    // Function call to find the MST
    primMST(graph);

    return 0;
}