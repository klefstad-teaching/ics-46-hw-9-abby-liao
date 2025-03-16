#include "dijkstras.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: ./dijkstras <filename>" << endl;
        return 1;
    }

    string filename = argv[1];

    int source = 0; 
    Graph G;
    file_to_graph(filename, G);

    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, source, previous);

    for (size_t destination = 0; destination < distances.size(); ++destination) {
        vector<int> path = extract_shortest_path(distances, previous, destination);
        

        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
        cout << "Total cost is " << distances[destination] << endl;
    }

    return 0;
}


