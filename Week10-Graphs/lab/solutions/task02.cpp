#include <iostream>
#include <vector>
#include <queue>

class Graph 
{
private:
    int vertices; // Number of vertices in the graph
    std::vector<std::vector<int>> adjacencyList; // Adjacency list representation of the graph
    
public:
    Graph(int vertices);
    void addEdge(int v, int w); // Function to add an edge to the graph
    void BFS(int startNode) const; // Breadth-First Search traversal
    std::size_t connectedComponents() const;
    void DFS(int startingNode, std::vector<bool>& visited) const;
};

Graph::Graph(int vertices)
    : vertices(vertices) 
{
    adjacencyList.resize(vertices);
}

void Graph::addEdge(int v, int w) 
{
    adjacencyList[v].push_back(w);
    adjacencyList[w].push_back(v); // Edge from w to v, since the graph is undirected
}

std::size_t Graph::connectedComponents() const
{
    std::vector<bool> visited(vertices, false);
    int count = 0;

    for (int v = 0; v < vertices; ++v) 
    {
        if (!visited[v]) 
        {
            DFS(v, visited);
            ++count;
        }
    }
    
    return count;
}

void Graph::DFS(int startingNode, std::vector<bool>& visited) const 
{
    visited[startingNode] = true;

    for (int neighbour : adjacencyList[startingNode])
    {
        if (!visited[neighbour])
        {
            DFS(neighbour, visited);
        }
    }
}

int main() 
{
    Graph g(7); // Create a graph with 7 vertices

    g.addEdge(0, 1);
    g.addEdge(0, 2);

    g.addEdge(4, 5);
    g.addEdge(4, 6);

    std::cout << g.connectedComponents() << std::endl;
    return 0;
}
