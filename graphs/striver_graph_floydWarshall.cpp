#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        const int INF = 1e8;

        // Convert -1 to INF and set diagonal to 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] == -1)
                    dist[i][j] = INF;

                if (i == j)
                    dist[i][j] = 0;
            }
        }

        // Floyd-Warshall Algorithm
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][via] != INF && dist[via][j] != INF) {
                        dist[i][j] = min(dist[i][j],
                                         dist[i][via] + dist[via][j]);
                    }
                }
            }
        }

        // Convert INF back to -1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] == INF)
                    dist[i][j] = -1;
            }
        }
    }
};