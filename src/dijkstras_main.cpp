#include "dijkstras.h"

int main() {
    vector<string> test_files = {"src/small.txt", "src/medium.txt", "src/large.txt", "src/largest.txt"};
    int destination = 3; 

    for (const string& filename : test_files) {
        cout << filename << endl;
        
        Graph G;
        file_to_graph(filename, G);

        int source = 0;
        vector<int> previous;
        vector<int> distances = dijkstra_shortest_path(G, source, previous);

        vector<int> path = extract_shortest_path(distances, previous, destination);
        cout << "Shortest path from " << source << " to " << destination << ": ";
        print_path(path, distances[destination]);
    }

    return 0;
}
