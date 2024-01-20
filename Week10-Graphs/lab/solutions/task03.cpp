#include <iostream>
#include <vector>
#include <queue>

class Graph 
{
private:
    int vertices; // Number of vertices in the graph
    std::vector<std::vector<int>> adjacencyList; // Adjacency list representation of the graph

    bool DFS_helper(int start, int end, std::vector<bool> &visited) const;
    
public:
    Graph(int vertices);
    void addEdge(int v, int w); // Function to add an edge to the graph
    bool hasPath(int start, int end) const;
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

bool Graph::DFS_helper(int start, int end, std::vector<bool> &visited) const 
{
    if (start == end) 
    {
        return true;
    }

    visited[start] = true;

    for (int neighbour : adjacencyList[start]) 
    {
        if (!visited[neighbour] && DFS_helper(neighbour, end, visited))
        {
            return true;
        }
    }

    return false;
}

bool Graph::hasPath(int start, int end) const
{
    std::vector<bool> visited(vertices, false);

    return DFS_helper(start, end, visited);
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
    g.addEdge(3, 5);

    int startVertex = 4;
    int endVertex = 5;
    
    std::cout << std::boolalpha << g.hasPath(startVertex, endVertex) << std::endl;

    return 0;
}
