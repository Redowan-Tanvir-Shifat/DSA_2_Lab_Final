#include <bits/stdc++.h>
using namespace std;

// DSU (Disjoint Set Union) data structure
// It helps in detecting cycles in the graph and efficiently managing connected components
class DSU
{
    int *parent; // Stores the parent of each node
    int *rank;   // Helps in balancing the tree (rank = tree height)

public:
    // Constructor to initialize DSU for `n` nodes
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];

        // Initially, each node is its own parent, and rank is 1
        for (int i = 0; i < n; i++)
        {
            parent[i] = -1; // -1 indicates that it is a root node
            rank[i] = 1;
        }
    }

    // Find function with path compression
    // It finds the representative/root of the set containing `i`
    int find(int i)
    {
        if (parent[i] == -1)
        {
            return i; // If `i` is its own parent, return `i`
        }

        return parent[i] = find(parent[i]); // Path compression for efficiency
    }

    // Union function to unite two sets containing `x` and `y`
    void unite(int x, int y)
    {
        int s1 = find(x); // Find the root of the set containing `x`
        int s2 = find(y); // Find the root of the set containing `y`

        if (s1 != s2)
        { // If they belong to different sets, unite them
            // Attach the smaller rank tree under the larger rank tree
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2; // `s1` becomes a child of `s2`
            }
            else if (rank[s1] > rank[s2])
            {
                parent[s2] = s1; // `s2` becomes a child of `s1`
            }
            else
            {
                // If ranks are equal, arbitrarily choose one to be the parent
                parent[s2] = s1;
                rank[s1] += 1; // Increase the rank of the new root
            }
        }
    }
};

// Graph class to represent a graph using an edge list
class Graph
{
    vector<vector<int>> edgelist; // Stores edges as {weight, node1, node2}
    int V;                        // Number of vertices

public:
    // Constructor to initialize a graph with `V` vertices
    Graph(int V) { this->V = V; }

    // Function to add an edge to the graph
    void addEdge(int x, int y, int w)
    {
        edgelist.push_back({w, x, y}); // Push edge as {weight, node1, node2}
    }

    // Kruskal's MST algorithm
    void kruskals_mst()
    {
        // Step 1: Sort all edges based on their weights
        sort(edgelist.begin(), edgelist.end());

        // Step 2: Initialize the DSU for all vertices
        DSU s(V);
        int ans = 0;   // To store the weight of the MST
        int count = 0; // To keep track of the number of edges in the MST

        cout << "Following are the edges in the constructed MST" << endl;

        // Step 3: Iterate through all edges in sorted order
        for (auto edge : edgelist)
        {
            int w = edge[0]; // Weight of the edge
            int x = edge[1]; // One endpoint of the edge
            int y = edge[2]; // Other endpoint of the edge

            // Step 4: Check if the current edge forms a cycle
            if (s.find(x) != s.find(y))
            {                  // If x and y are in different sets
                s.unite(x, y); // Unite the sets containing x and y
                ans += w;      // Add the weight of the edge to the MST
                cout << x << " -- " << y << " == " << w << endl;
                count++; // Increment the count of edges in the MST
            }

            // Optimization: Stop if MST is complete (V-1 edges)
            if (count == V - 1)
            {
                break;
            }
        }

        // Print the total weight of the MST
        cout << "Minimum Cost Spanning Tree: " << ans;
    }
};

// Driver code
int main()
{
    Graph g(4); // Create a graph with 4 vertices

    // Add edges with their weights
    g.addEdge(0, 1, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 0, 6);
    g.addEdge(0, 3, 5);

    // Function call to find and print the MST
    g.kruskals_mst();

    return 0;
}