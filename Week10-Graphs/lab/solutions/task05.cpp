#include <iostream>
#include <vector>
#include <queue>

struct Edge 
{
    int to;
    int weight;

    Edge(int to, int weight) : to(to), weight(weight) {}
};


class Graph 
{
private:
    int vertices; // Number of vertices in the graph
    std::vector<std::vector<Edge>> adjacencyList; // Adjacency list representation of the graph
    
public:
    Graph(int vertices);
    void addEdge(int from, int to, int weight); // Function to add an edge to the graph
    std::vector<int> dijkstra(int startNode) const;
};

Graph::Graph(int vertices)
    : vertices(vertices) 
{
    adjacencyList.resize(vertices);
}

void Graph::addEdge(int from, int to, int weight) 
{
    adjacencyList[from].push_back(Edge(to, weight));
}

std::vector<int> Graph::dijkstra(int startNode) const
{
    std::vector<int> destinations(vertices, std::numeric_limits<int>::max());
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;

    destinations[startNode] = 0;
    pq.push(std::make_pair(0, startNode));

    while (!pq.empty()) 
    {
        int u = pq.top().second;
        pq.pop();

        for (const Edge& edge : adjacencyList[u]) 
        {
            if (destinations[u] + edge.weight < destinations[edge.to]) 
            {
                destinations[edge.to] = destinations[u] + edge.weight;
                pq.push(std::make_pair(destinations[edge.to], edge.to));
            }
        }
    }

    return destinations;
}

int main() 
{
    Graph g(5); // Create a graph with 5 vertices

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 4, 3);
    g.addEdge(2, 1, 1);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 4, 5);
    g.addEdge(4, 3, 1);

    int startVertex = 0;
    std::vector<int> distances = g.dijkstra(startVertex);

    for (int i = 0; i < distances.size(); ++i)
    {
        std::cout << "Distance from " << startVertex << " to " << i << " is " << distances[i] << std::endl;
    }

    return 0;
}
