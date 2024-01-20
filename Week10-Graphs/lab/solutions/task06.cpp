#include <iostream>
#include <vector>
#include <queue>

struct Edge 
{
    int from, to, weight;

    Edge(int from, int to, int weight) : from(from), to(to), weight(weight) {}

    bool operator < (const Edge& other) const
    {
        return this->weight > other.weight;
    }
};

#include <vector>
#include <queue>
#include <limits>

class Graph 
{
private:
    int vertices;
    std::vector<std::vector<Edge>> adjacencyList;

public:
    Graph(int vertices);
    void addEdge(int from, int to, int weight);

    int sumOfMinimalSpanningTree(int startVertex) const;
};


Graph::Graph(int vertices)
    : vertices(vertices) 
{
    adjacencyList.resize(vertices);
}

void Graph::addEdge(int from, int to, int weight) 
{
    adjacencyList[from].push_back(Edge(from, to, weight));
    adjacencyList[to].push_back(Edge(to, from, weight)); // Add edge in reverse direction
}

int Graph::sumOfMinimalSpanningTree(int startVertex) const
{
    int sum = 0;
    std::vector<bool> inMST(vertices, false);
    std::priority_queue<Edge> pq;

    // Start from the first vertex
    inMST[startVertex] = true;
    for (const Edge& e : adjacencyList[startVertex]) 
    {
        pq.push(e);
    }

    while (!pq.empty()) 
    {
        Edge currentEdge = pq.top();
        pq.pop();

        if (inMST[currentEdge.to]) 
        {
            continue; // Skip if the vertex is already in MST
        }

        // Include the vertex in MST
        inMST[currentEdge.to] = true;
        sum += currentEdge.weight;

        // Add all edges from this vertex to the priority queue
        for (const Edge& neighbor : adjacencyList[currentEdge.to])
         {
            if (!inMST[neighbor.to]) 
            {
                pq.push(neighbor);
            }
        }
    }

    return sum;
}

int main() 
{
    Graph g(7); // Create a graph with 7 vertices

    g.addEdge(0, 3, 2);
    g.addEdge(0, 2, 3);
    g.addEdge(0, 1, 3);

    g.addEdge(1, 2, 4);
    g.addEdge(1, 4, 3);

    g.addEdge(2, 3, 5);
    g.addEdge(2, 4, 1);
    g.addEdge(2, 5, 6);

    g.addEdge(3, 5, 7);

    g.addEdge(4, 5, 8);

    g.addEdge(5, 6, 9);

    int startVertex = 0;
    std::cout << g.sumOfMinimalSpanningTree(startVertex) << std::endl;

    return 0;
}
