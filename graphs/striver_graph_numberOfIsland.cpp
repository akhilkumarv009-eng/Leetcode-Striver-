#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void bfs(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &vis) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;   // Mark starting cell visited

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            // Up
            if (x - 1 >= 0 && !vis[x - 1][y] && grid[x - 1][y] == '1') {
                vis[x - 1][y] = 1;
                q.push({x - 1, y});
            }

            // Left
            if (y - 1 >= 0 && !vis[x][y - 1] && grid[x][y - 1] == '1') {
                vis[x][y - 1] = 1;
                q.push({x, y - 1});
            }

            // Down
            if (x + 1 < n && !vis[x + 1][y] && grid[x + 1][y] == '1') {
                vis[x + 1][y] = 1;
                q.push({x + 1, y});
            }

            // Right
            if (y + 1 < m && !vis[x][y + 1] && grid[x][y + 1] == '1') {
                vis[x][y + 1] = 1;
                q.push({x, y + 1});
            }
        }
    }

    int numIslands(vector<vector<char>> &grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    bfs(i, j, grid, vis);
                    count++;
                }
            }
        }

        return count;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    cout << "Number of Islands: " << obj.numIslands(grid) << endl;

    return 0;
}