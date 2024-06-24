#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

typedef std::pair<int, int> Edge; 
typedef std::vector<std::vector<Edge>> Graph;

const int INF = std::numeric_limits<int>::max();

void addEdge(Graph &graph, int u, int v, int weight) {
    graph[u].emplace_back(v, weight);
    graph[v].emplace_back(u, weight);
}

std::vector<int> dijkstra(const Graph &graph, int start) {
    int n = graph.size();
    std::vector<int> dist(n, INF);
    dist[start] = 0;

    std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;
    pq.emplace(0, start);

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (const Edge &edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.emplace(dist[v], v);
            }
        }
    }

    return dist;
}

int main() {
    int V, E;
    std::cout << "Digite o número de vértices: ";
    std::cin >> V;

    Graph graph(V);

    std::cout << "Digite o número de arestas: ";
    std::cin >> E;

    std::cout << "Digite as arestas no formato (origem destino peso):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, weight;
        std::cin >> u >> v >> weight;
        addEdge(graph, u, v, weight);
    }

    int start;
    std::cout << "Digite o vértice inicial: ";
    std::cin >> start;

    std::vector<int> distances = dijkstra(graph, start);

    std::cout << "Distâncias a partir do vértice " << start << ":\n";
    for (int i = 0; i < distances.size(); ++i) {
        if (distances[i] == INF) {
            std::cout << "Vértice " << i << ": INF\n";
        } else {
            std::cout << "Vértice " << i << ": " << distances[i] << '\n';
        }
    }

    return 0;
}
