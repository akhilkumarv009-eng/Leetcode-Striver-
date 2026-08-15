#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        if (src == dst)
            return 0;

        vector<pair<int, int>> adj[n];

        for (auto &it : flights) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
        }

        queue<pair<int, pair<int, int>>> q;
        // {node, {cost, stops}}

        vector<int> dis(n, 1e9);

        dis[src] = 0;
        q.push({src, {0, 0}});

        while (!q.empty()) {

            int node = q.front().first;
            int cost = q.front().second.first;
            int stops = q.front().second.second;
            q.pop();

            if (stops > k)
                continue;

            for (auto it : adj[node]) {

                int adjNode = it.first;
                int wt = it.second;

                if (cost + wt < dis[adjNode]) {

                    dis[adjNode] = cost + wt;
                    q.push({adjNode, {cost + wt, stops + 1}});
                }
            }
        }

        return (dis[dst] == 1e9) ? -1 : dis[dst];
    }
};

int main() {
    Solution obj;

    int n = 4;
    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 0, 100},
        {1, 3, 600},
        {2, 3, 200}
    };

    int src = 0;
    int dst = 3;
    int k = 1;

    cout << obj.findCheapestPrice(n, flights, src, dst, k);

    return 0;
}