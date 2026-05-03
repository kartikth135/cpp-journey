#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii;

vector<int> dijkstra(vector<vector<pii>>& graph, int src, int n) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Skip if outdated
        if (d > dist[u]) continue;

        for (auto& [w, v] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int n = 6; // nodes 0 to 5
    vector<vector<pii>> graph(n);

    // Add edges {weight, destination}
    graph[0].push_back({4, 1});
    graph[0].push_back({2, 2});
    graph[1].push_back({5, 3});
    graph[2].push_back({1, 1});
    graph[2].push_back({8, 4});
    graph[3].push_back({2, 5});
    graph[4].push_back({3, 5});
    graph[1].push_back({6, 4});

    int src = 0;
    vector<int> dist = dijkstra(graph, src, n);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": ";
        if (dist[i] == INT_MAX) cout << "unreachable\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}