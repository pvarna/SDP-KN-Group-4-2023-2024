#include <vector>
#include <unordered_map>
#include <algorithm>

class UnionFind {
public:
    std::unordered_map<int, int> parent;
    std::unordered_map<int, int> size;

    UnionFind(const std::vector<int>& nodes) 
    {
        for (const int node : nodes) 
        {
            parent[node] = node;
            size[node] = 1;
        }
    }

    int find(int node) 
    {
        if (node == parent[node]) 
        {
            return node;
        }

        return parent[node] = find(parent[node]);
    }

    bool Union(int u, int v) 
    {
        int uParent = find(u);
        int vParent = find(v);

        if (uParent == vParent)
        {
            return false;
        }

        if (size[uParent] < size[vParent]) 
        {
            parent[uParent] = vParent;
            ++size[vParent];
        }
        else 
        {
            parent[vParent] = uParent;
            ++size[uParent];
        }

        return true;
    }
};

class Edge {
public:
    int from;
    int to;
    int weight;

    Edge(int from, int to, int weight) : from(from), to(to), weight(weight) {}

    bool operator<(const Edge& other) const 
    {
        return this->weight < other.weight;
    }
};


std::vector<Edge> kruskal(std::vector<Edge>& edges, int nodesCount) {
    
    sort(edges.begin(), edges.end());

    std::vector<int> nodes;
    for (int i = 0; i < nodesCount; i++) 
    {
        nodes.push_back(i);
    }

    UnionFind unf(nodes);
    std::vector<Edge> tree;

    for (const Edge& edge : edges) 
    {
        int from = edge.from;
        int to = edge.to;

        if (unf.Union(from, to)) 
        {
            tree.push_back(edge);
        }
    }

    return tree;
}
