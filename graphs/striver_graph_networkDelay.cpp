#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        int m = times.size();

        vector<pair<int, int>> adj[n + 1];

        for (int i = 0; i < m; i++) {
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];

            adj[u].push_back({v, wt});
        }

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<int> dis(n + 1, 1000000000);

        dis[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {

            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Skip outdated entries
            if (time > dis[node])
                continue;

            for (auto it : adj[node]) {

                int v = it.first;
                int wt = it.second;

                if (dis[v] > time + wt) {
                    dis[v] = time + wt;
                    pq.push({time + wt, v});
                }
            }
        }

        int maxTime = 0;

        for (int i = 1; i <= n; i++) {
            if (dis[i] == 1000000000)
                return -1;

            maxTime = max(maxTime, dis[i]);
        }

        return maxTime;
    }
};

int main() {

    Solution obj;

    int n = 4;
    vector<vector<int>> times = {
        {2, 1, 1},
        {2, 3, 1},
        {3, 4, 1}
    };

    int k = 2;

    cout << obj.networkDelayTime(times, n, k);

    return 0;
}