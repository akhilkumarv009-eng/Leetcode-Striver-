#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        const int INF = 1e9;

        vector<vector<int>> ans(n, vector<int>(n, INF));

        // Initialize edges
        for (auto it : edges) {
            ans[it[0]][it[1]] = it[2];
            ans[it[1]][it[0]] = it[2];
        }

        // Distance from a city to itself
        for (int i = 0; i < n; i++) {
            ans[i][i] = 0;
        }

        // Floyd-Warshall
        for (int vis = 0; vis < n; vis++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {

                    if (ans[i][vis] != INF && ans[vis][j] != INF) {
                        ans[i][j] = min(ans[i][j],
                                        ans[i][vis] + ans[vis][j]);
                    }

                }
            }
        }

        int cnt2 = INF;
        int answer = 0;

        // Count reachable cities
        for (int i = 0; i < n; i++) {

            int cnt = 0;

            for (int j = 0; j < n; j++) {
                if (ans[i][j] <= distanceThreshold) {
                    cnt++;
                }
            }

            // Smaller count, or tie with larger index
            if (cnt <= cnt2) {
                cnt2 = cnt;
                answer = i;
            }
        }

        return answer;
    }
};