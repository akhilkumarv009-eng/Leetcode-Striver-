#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        const int MOD = 1e9 + 7;

        vector<pair<int, int>> adj[n];

        for (auto &it : roads) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        vector<long long> dis(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        dis[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while (!pq.empty()) {

            long long cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (cost > dis[node])
                continue;

            for (auto &it : adj[node]) {

                int adjNode = it.first;
                int wt = it.second;

                if (dis[adjNode] > cost + wt) {
                    dis[adjNode] = cost + wt;
                    ways[adjNode] = ways[node];
                    pq.push({dis[adjNode], adjNode});
                }
                else if (dis[adjNode] == cost + wt) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};

int main() {

    Solution obj;

    int n = 7;

    vector<vector<int>> roads = {
        {0,6,7},
        {0,1,2},
        {1,2,3},
        {1,3,3},
        {6,3,3},
        {3,5,1},
        {6,5,1},
        {2,5,1},
        {0,4,5},
        {4,6,2}
    };

    cout << "Number of shortest paths = "
         << obj.countPaths(n, roads) << endl;

    return 0;
}