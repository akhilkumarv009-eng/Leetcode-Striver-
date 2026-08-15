#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<pair<int, int>, int>> q;

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> ans(n, vector<int>(m, 0));

        // Push all 0s into the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    vis[i][j] = 1;
                    ans[i][j] = 0;
                    q.push({{i, j}, 0});
                }
            }
        }

        // Multi-source BFS
        while (!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            // Up
            if (i - 1 >= 0 && !vis[i - 1][j] && mat[i - 1][j] == 1) {
                vis[i - 1][j] = 1;
                ans[i - 1][j] = dist + 1;
                q.push({{i - 1, j}, dist + 1});
            }

            // Left
            if (j - 1 >= 0 && !vis[i][j - 1] && mat[i][j - 1] == 1) {
                vis[i][j - 1] = 1;
                ans[i][j - 1] = dist + 1;
                q.push({{i, j - 1}, dist + 1});
            }

            // Down
            if (i + 1 < n && !vis[i + 1][j] && mat[i + 1][j] == 1) {
                vis[i + 1][j] = 1;
                ans[i + 1][j] = dist + 1;
                q.push({{i + 1, j}, dist + 1});
            }

            // Right
            if (j + 1 < m && !vis[i][j + 1] && mat[i][j + 1] == 1) {
                vis[i][j + 1] = 1;
                ans[i][j + 1] = dist + 1;
                q.push({{i, j + 1}, dist + 1});
            }
        }

        return ans;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    Solution obj;
    vector<vector<int>> ans = obj.updateMatrix(mat);

    cout << "Output Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}