/*
 * PR Details:
 * Description of Changes:
 *   This PR implements Prim's algorithm to find the Minimum Spanning Tree (MST) of a connected, undirected, weighted graph.
 *   The MST is a subset of the edges that connects all the vertices together, without any cycles, and with the minimum possible total edge weight.
 *   If the graph is disconnected, the program notifies the user.
 *
 * Related Issues/Discussions:
 *   (Add links to related issues or discussions here, if any)
 *
 * Author: Rakesh Jena
 */

#include <iostream>
#include <vector>
using namespace std;

// Define a large value to represent infinity (no edge)
#define INF 999999

int main()
{
    // Number of vertices in the graph
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    // Adjacency matrix to store the graph's edge weights
    vector<vector<int>> cost(V, vector<int>(V));

    // Read the adjacency matrix from the user
    cout << "Enter adjacency matrix (0 if no edge):\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> cost[i][j];
            // Replace 0 with INF to represent no edge
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    // Track visited vertices
    vector<bool> visited(V, false);
    // Start with the first vertex (vertex 0)
    visited[0] = true;

    // Number of edges added to the MST so far
    int edges_in_mst = 0;
    // Total cost of the MST
    int total_cost = 0;

    cout << "\nEdges in MST:\n";

    // Loop until all vertices are included in the MST
    while (edges_in_mst < V - 1)
    {
        // Initialize minimum cost to a large value
        int min_cost = INF;
        // Variables to store the vertices of the minimum edge
        int u = -1, v = -1;

        // Find the minimum edge connecting a visited vertex to an unvisited vertex
        for (int i = 0; i < V; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < V; j++)
                {
                    // If vertex j is not visited and the edge cost is less than the current minimum
                    if (!visited[j] && cost[i][j] < min_cost)
                    {
                        min_cost = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        // If no minimum edge is found, the graph is disconnected
        if (u == -1 || v == -1)
        {
            cout << "Graph is disconnected. MST cannot be formed.\n";
            break;
        }

        // Print the edge and its cost
        cout << u << " - " << v << "  cost: " << min_cost << "\n";
        // Add the edge cost to the total cost
        total_cost += min_cost;
        // Mark vertex v as visited
        visited[v] = true;
        // Increment the number of edges in the MST
        edges_in_mst++;
    }

    // Print the total cost of the MST
    cout << "\nTotal cost of MST = " << total_cost << "\n";

    return 0;
}
