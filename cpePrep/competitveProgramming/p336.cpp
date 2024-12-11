#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

// Perform BFS to determine reachable nodes within a given TTL
int BFS(map<int, vector<int> >& graph, int startNode, int ttl) {
    map<int, int> distance;     // Keeps track of the distance from the start node
    queue<int> q;               // Queue for BFS

    q.push(startNode);
    distance[startNode] = 0;    // Distance to start node is zero

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        // Process all the neighbors of the current node
        for(int neighbor : graph[node]) {
            if (distance.find(neighbor) == distance.end()) {
                distance[neighbor] = distance[node] + 1;
                if (distance[neighbor] > ttl) continue;
                q.push(neighbor);
            }
        }
    }

    // Count nodes that are either not visited or exceed the TTL
    int unreachableCount = 0;
    for(const auto& entry : graph) {
        if(distance.find(entry.first) == distance.end() || distance[entry.first] > ttl) {
            unreachableCount++;
        }
    }

    return unreachableCount;
}

int main() {
    int caseNumber = 1;         // Track the case number for output

    while(true) {
        int NC;                 // Number of connections
        cin >> NC;
        if (NC == 0) break;     // End of input

        map<int, vector<int> > graph;   // Graph representation

        // Read connections between nodes
        for (int i = 0; i < NC; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);      // Add connection u -> v
            graph[v].push_back(u);      // Add connection v -> u (since it's undirected)
        }

        // Handle queries for reachability
        while(true) {
            int startNode, ttl;
            cin >> startNode >> ttl;
            if (startNode == 0 && ttl == 0) break;      // End of queries for this network

            // Calculate the number of unreachable nodes
            int unreachableNodes = BFS(graph, startNode, ttl);

            // Output result for this case
            cout << "Case " << caseNumber++ << ": " << unreachableNodes
                 << " nodes not reachable from node " << startNode
                 << " with TTL = " << ttl << "." << endl;
        }
    }

    return 0;
}