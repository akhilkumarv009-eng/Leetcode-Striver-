#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& board) {
        if (board.empty()) return 0;

        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int,int>> q;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        // Add all boundary land cells
        for(int i = 0; i < n; i++) {
            if(board[i][0] == 1 && !vis[i][0]) {
                vis[i][0] = 1;
                q.push({i,0});
            }

            if(board[i][m-1] == 1 && !vis[i][m-1]) {
                vis[i][m-1] = 1;
                q.push({i,m-1});
            }
        }

        for(int j = 0; j < m; j++) {
            if(board[0][j] == 1 && !vis[0][j]) {
                vis[0][j] = 1;
                q.push({0,j});
            }

            if(board[n-1][j] == 1 && !vis[n-1][j]) {
                vis[n-1][j] = 1;
                q.push({n-1,j});
            }
        }

        // BFS from all boundary land
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx >= 0 && nx < n &&
                   ny >= 0 && ny < m &&
                   !vis[nx][ny] &&
                   board[nx][ny] == 1) {

                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }

        // Count unvisited land cells
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 1 && !vis[i][j])
                    ans++;
            }
        }

        return ans;
    }
};