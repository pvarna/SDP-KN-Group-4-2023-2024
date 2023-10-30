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
    void BFS(int startNode); // Breadth-First Search traversal
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

void Graph::BFS(int startNode) 
{
    std::vector<bool> visited(this->vertices, false);
    std::queue<int> q;
    q.push(startNode);

    while (!q.empty()) 
    {
        int current = q.front();
        q.pop();

        if (!visited[current]) 
        {
            std::cout << current << " ";
            visited[current] = true;

            for (int neighbour : adjacencyList[current]) 
            {
                if (!visited[neighbour]) 
                {
                    q.push(neighbour);
                }
            }
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

    g.BFS(0);
    std::cout << std::endl;
    return 0;
}
