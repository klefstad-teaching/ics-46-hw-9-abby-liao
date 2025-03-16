#include "dijkstras.h"
#include <algorithm>



vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int numVertices = G.numVertices;
    vector<int> distances(numVertices, INF);
    vector<bool> visited(numVertices, false);
    
    distances[source] = 0;
    previous.assign(numVertices, -1); 
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
    minHeap.push({0, source}); 
    
    while (!minHeap.empty()) {
        int u = minHeap.top().second;
        minHeap.pop();
        
        if (visited[u]) continue;
        visited[u] = true;

        for (const Edge& e : G[u]) {
            int v = e.dst, weight = e.weight;
            if (!visited[v] && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                minHeap.push({distances[v], v}); 
            }
        }
    }
    return distances;
}


vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination) {
    vector<int> path;
    for (int at = destination; at != -1; at = previous[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());
    return path;
}

void print_path(const vector<int>& path, int total) {
    if (total == INF) {
        cout << "No path found.\n";
        return;
    }
    if (!path.empty()) {
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }
    cout << endl; 
    cout << "Total cost is " << total << endl;
}


