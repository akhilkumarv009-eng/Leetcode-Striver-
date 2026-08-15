#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class disjointset
{
public:
    vector<int> parent;
    vector<int> Size;

    void makeset(int n)
    {
        parent.resize(n);
        Size.resize(n);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            Size[i] = 1;
        }
    }

    int findparent(int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findparent(parent[node]);
    }

    void unionbysize(int u, int v)
    {
        int pu = findparent(u);
        int pv = findparent(v);

        if (pu == pv)
            return;

        if (Size[pu] < Size[pv])
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
    int removeStones(vector<vector<int>> &stones)
    {
        int maxRow = 0;
        int maxCol = 0;

        for (auto &it : stones)
        {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        // Total number of nodes required
        int totalNodes = maxRow + maxCol + 2;

        disjointset ds;
        ds.makeset(totalNodes);

        unordered_map<int, int> stoneNodes;

        for (auto &it : stones)
        {
            int rowNode = it[0];
            int colNode = it[1] + maxRow + 1;

            ds.unionbysize(rowNode, colNode);

            stoneNodes[rowNode] = 1;
            stoneNodes[colNode] = 1;
        }

        int components = 0;

        for (auto &it : stoneNodes)
        {
            if (ds.findparent(it.first) == it.first)
                components++;
        }

        return stones.size() - components;
    }
};

int main()
{
    Solution obj;

    vector<vector<int>> stones = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 2},
        {2, 1},
        {2, 2}};

    cout << "Maximum stones that can be removed: "
         << obj.removeStones(stones) << endl;

    return 0;
}