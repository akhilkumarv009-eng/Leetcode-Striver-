#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {

        if (board.empty()) return;

        int n = board.size();
        int m = board[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int i, j;

        // Top boundary
        for(i = 0; i < m; i++)
        {
            if(board[0][i] == 'O' && !vis[0][i])
            {
                q.push({0, i});
                vis[0][i] = 1;

                while(!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    if(y+1 < m && !vis[x][y+1] && board[x][y+1]=='O')
                    {
                        vis[x][y+1]=1;
                        q.push({x,y+1});
                    }

                    if(y-1 >= 0 && !vis[x][y-1] && board[x][y-1]=='O')
                    {
                        vis[x][y-1]=1;
                        q.push({x,y-1});
                    }

                    if(x+1 < n && !vis[x+1][y] && board[x+1][y]=='O')
                    {
                        vis[x+1][y]=1;
                        q.push({x+1,y});
                    }

                    if(x-1 >= 0 && !vis[x-1][y] && board[x-1][y]=='O')
                    {
                        vis[x-1][y]=1;
                        q.push({x-1,y});
                    }
                }
            }
        }

        // Bottom boundary
        for(i = 0; i < m; i++)
        {
            if(board[n-1][i] == 'O' && !vis[n-1][i])
            {
                q.push({n-1, i});
                vis[n-1][i] = 1;

                while(!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    if(y+1 < m && !vis[x][y+1] && board[x][y+1]=='O')
                    {
                        vis[x][y+1]=1;
                        q.push({x,y+1});
                    }

                    if(y-1 >= 0 && !vis[x][y-1] && board[x][y-1]=='O')
                    {
                        vis[x][y-1]=1;
                        q.push({x,y-1});
                    }

                    if(x+1 < n && !vis[x+1][y] && board[x+1][y]=='O')
                    {
                        vis[x+1][y]=1;
                        q.push({x+1,y});
                    }

                    if(x-1 >= 0 && !vis[x-1][y] && board[x-1][y]=='O')
                    {
                        vis[x-1][y]=1;
                        q.push({x-1,y});
                    }
                }
            }
        }

        // Left boundary
        for(i = 0; i < n; i++)
        {
            if(board[i][0] == 'O' && !vis[i][0])
            {
                q.push({i,0});
                vis[i][0] = 1;

                while(!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    if(y+1 < m && !vis[x][y+1] && board[x][y+1]=='O')
                    {
                        vis[x][y+1]=1;
                        q.push({x,y+1});
                    }

                    if(y-1 >= 0 && !vis[x][y-1] && board[x][y-1]=='O')
                    {
                        vis[x][y-1]=1;
                        q.push({x,y-1});
                    }

                    if(x+1 < n && !vis[x+1][y] && board[x+1][y]=='O')
                    {
                        vis[x+1][y]=1;
                        q.push({x+1,y});
                    }

                    if(x-1 >= 0 && !vis[x-1][y] && board[x-1][y]=='O')
                    {
                        vis[x-1][y]=1;
                        q.push({x-1,y});
                    }
                }
            }
        }

        // Right boundary
        for(i = 0; i < n; i++)
        {
            if(board[i][m-1] == 'O' && !vis[i][m-1])
            {
                q.push({i,m-1});
                vis[i][m-1] = 1;

                while(!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    if(y+1 < m && !vis[x][y+1] && board[x][y+1]=='O')
                    {
                        vis[x][y+1]=1;
                        q.push({x,y+1});
                    }

                    if(y-1 >= 0 && !vis[x][y-1] && board[x][y-1]=='O')
                    {
                        vis[x][y-1]=1;
                        q.push({x,y-1});
                    }

                    if(x+1 < n && !vis[x+1][y] && board[x+1][y]=='O')
                    {
                        vis[x+1][y]=1;
                        q.push({x+1,y});
                    }

                    if(x-1 >= 0 && !vis[x-1][y] && board[x-1][y]=='O')
                    {
                        vis[x-1][y]=1;
                        q.push({x-1,y});
                    }
                }
            }
        }

        // Convert surrounded O's to X
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                if(board[i][j] == 'O' && !vis[i][j])
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};