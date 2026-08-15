#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        // Start or destination blocked
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        vector<vector<int>> dis(n, vector<int>(n, 1e9));

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        dis[0][0] = 1;
        pq.push({1,{0,0}});

        while (!pq.empty())
        {
            int distance = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            // Skip outdated entries
            if(distance > dis[x][y])
                continue;

            // Destination reached
            if(x == n-1 && y == n-1)
                return distance;

            // Down
            if(x+1<n && grid[x+1][y]==0 && dis[x+1][y]>distance+1)
            {
                dis[x+1][y]=distance+1;
                pq.push({dis[x+1][y],{x+1,y}});
            }

            // Up
            if(x-1>=0 && grid[x-1][y]==0 && dis[x-1][y]>distance+1)
            {
                dis[x-1][y]=distance+1;
                pq.push({dis[x-1][y],{x-1,y}});
            }

            // Right
            if(y+1<n && grid[x][y+1]==0 && dis[x][y+1]>distance+1)
            {
                dis[x][y+1]=distance+1;
                pq.push({dis[x][y+1],{x,y+1}});
            }

            // Left
            if(y-1>=0 && grid[x][y-1]==0 && dis[x][y-1]>distance+1)
            {
                dis[x][y-1]=distance+1;
                pq.push({dis[x][y-1],{x,y-1}});
            }

            // Down-Right
            if(x+1<n && y+1<n && grid[x+1][y+1]==0 && dis[x+1][y+1]>distance+1)
            {
                dis[x+1][y+1]=distance+1;
                pq.push({dis[x+1][y+1],{x+1,y+1}});
            }

            // Down-Left
            if(x+1<n && y-1>=0 && grid[x+1][y-1]==0 && dis[x+1][y-1]>distance+1)
            {
                dis[x+1][y-1]=distance+1;
                pq.push({dis[x+1][y-1],{x+1,y-1}});
            }

            // Up-Right
            if(x-1>=0 && y+1<n && grid[x-1][y+1]==0 && dis[x-1][y+1]>distance+1)
            {
                dis[x-1][y+1]=distance+1;
                pq.push({dis[x-1][y+1],{x-1,y+1}});
            }

            // Up-Left
            if(x-1>=0 && y-1>=0 && grid[x-1][y-1]==0 && dis[x-1][y-1]>distance+1)
            {
                dis[x-1][y-1]=distance+1;
                pq.push({dis[x-1][y-1],{x-1,y-1}});
            }
        }

        return -1;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> grid[i][j];

    Solution obj;
    cout << obj.shortestPathBinaryMatrix(grid);

    return 0;
}