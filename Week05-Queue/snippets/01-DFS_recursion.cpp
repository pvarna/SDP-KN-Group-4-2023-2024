#include <iostream>
#include <vector>
#include <stack>

class Graph 
{
private:
    int vertices; // Number of vertices in the graph
    std::vector<std::vector<int>> adjacencyList; // Adjacency list representation of the graph
    void DFSUtil(int node, std::vector<bool>& visited);

public:
    Graph(int vertices);
    void addEdge(int v, int w); // Function to add an edge to the graph
    void DFS(int startNode); // Depth-First Search traversal
};

Graph::Graph(int vertices)
    : vertices(vertices) 
{
    adjacencyList.resize(vertices);
}

void Graph::addEdge(int v, int w) 
{
    adjacencyList[v].push_back(w);
}

void Graph::DFS(int startNode) 
{
    std::vector<bool> visited(vertices, false);
    DFSUtil(startNode, visited);
}

void Graph::DFSUtil(int node, std::vector<bool>& visited)
{
    std::cout << node << " ";
    visited[node] = true;

    for (int neighbour : adjacencyList[node]) 
    {
        if (!visited[neighbour]) 
        {
            DFSUtil(neighbour, visited);
        }
    }
}

int main() 
{
    Graph g(7); // Create a graph with 7 vertices

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);

    g.DFS(0);
    std::cout << std::endl;
    return 0;
}
