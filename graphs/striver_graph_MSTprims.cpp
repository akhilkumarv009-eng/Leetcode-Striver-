#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {

        vector<pair<int, int>> adj[V];

        // Build adjacency list
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // Min Heap {weight, node}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<int> vis(V, 0);

        // Start from node 0
        pq.push({0, 0});

        int sum = 0;

        while (!pq.empty()) {
            auto element = pq.top();
            pq.pop();

            int wt = element.first;
            int node = element.second;

            if (vis[node])
                continue;

            vis[node] = 1;
            sum += wt;

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edgeWt = it.second;

                if (!vis[adjNode]) {
                    pq.push({edgeWt, adjNode});
                }
            }
        }

        return sum;
    }
};

int main() {
    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> edges;

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    Solution obj;
    cout << "Weight of Minimum Spanning Tree = "
         << obj.spanningTree(V, edges) << endl;

    return 0;
}