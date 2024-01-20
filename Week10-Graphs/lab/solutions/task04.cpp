#include <iostream>
#include <vector>
#include <queue>

class Graph 
{
private:
    int vertices; // Number of vertices in the graph
    std::vector<std::vector<int>> adjacencyList; // Adjacency list representation of the graph

    bool isCyclicHelper(int v, std::vector<bool>& visited, std::vector<bool>& recursionStack) const;
    
public:
    Graph(int vertices);
    void addEdge(int v, int w); // Function to add an edge to the graph
    bool isCyclic() const;
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

bool Graph::isCyclicHelper(int v, std::vector<bool>& visited, std::vector<bool>& recursionStack) const
{
    if(!visited[v])
    {
        visited[v] = true;
        recursionStack[v] = true;

        for(int neighbour : adjacencyList[v])
        {
            if ((!visited[neighbour] && isCyclicHelper(neighbour, visited, recursionStack)) || recursionStack[neighbour])
            {
                return true;
            }
        }
    }

    recursionStack[v] = false;  // remove the vertex from recursion stack
    return false;
}


bool Graph::isCyclic() const
{
    std::vector<bool> visited(vertices, false);
    std::vector<bool> recStack(vertices, false);

    for (int i = 0; i < vertices; i++)
    {
        if (isCyclicHelper(i, visited, recStack))
        {
            return true;
        }
    }

    return false;
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

    g.addEdge(5, 6);
    g.addEdge(6, 2);

    std::cout << std::boolalpha << g.isCyclic() << std::endl;
    return 0;
}
