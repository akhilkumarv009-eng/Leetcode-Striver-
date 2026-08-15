#include <iostream>
#include <vector>
using namespace std;

class dsu
{
public:
    vector<int> parent;
    vector<int> Size;

    void makeset(int n)
    {
        parent.resize(n);
        Size.resize(n);

        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
            Size[i] = 1;
        }
    }

    int findparent(int node)
    {
        if(node == parent[node])
            return node;

        return parent[node] = findparent(parent[node]);
    }

    void unionbysize(int u, int v)
    {
        int pu = findparent(u);
        int pv = findparent(v);

        if(pu == pv)
            return;

        if(Size[pu] < Size[pv])
        {
            parent[pu] = pv;
            Size[pv] += Size[pu];
        }
        else
        {
            parent[pv] = pu;
            Size[pu] += Size[pv];
        }
    }
};

class Solution
{
public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        dsu dv;
        dv.makeset(n * m);

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cnt = 0;
        vector<int> ans;

        for(auto it : operators)
        {
            int row = it[0];
            int col = it[1];

            if(vis[row][col] == 1)
            {
                ans.push_back(cnt);
                continue;
            }

            vis[row][col] = 1;
            cnt++;

            // Up
            if(row - 1 >= 0 &&
               vis[row - 1][col] == 1 &&
               dv.findparent(row * m + col) != dv.findparent((row - 1) * m + col))
            {
                cnt--;
                dv.unionbysize(row * m + col, (row - 1) * m + col);
            }

            // Left
            if(col - 1 >= 0 &&
               vis[row][col - 1] == 1 &&
               dv.findparent(row * m + col) != dv.findparent(row * m + (col - 1)))
            {
                cnt--;
                dv.unionbysize(row * m + col, row * m + (col - 1));
            }

            // Down
            if(row + 1 < n &&
               vis[row + 1][col] == 1 &&
               dv.findparent(row * m + col) != dv.findparent((row + 1) * m + col))
            {
                cnt--;
                dv.unionbysize(row * m + col, (row + 1) * m + col);
            }

            // Right
            if(col + 1 < m &&
               vis[row][col + 1] == 1 &&
               dv.findparent(row * m + col) != dv.findparent(row * m + (col + 1)))
            {
                cnt--;
                dv.unionbysize(row * m + col, row * m + (col + 1));
            }

            ans.push_back(cnt);
        }

        return ans;
    }
};

int main()
{
    int n = 4, m = 5;

    vector<vector<int>> operators = {
        {1,1},
        {0,1},
        {3,3},
        {3,4}
    };

    Solution obj;
    vector<int> ans = obj.numOfIslands(n, m, operators);

    for(int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}