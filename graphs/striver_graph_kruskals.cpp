#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class disjointSet
{
public:

    vector<int> parent;
    vector<int> Size;

    void makeset(int n)
    {
        parent.resize(n + 1);
        Size.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            Size[i] = 1;
        }
    }

    int findparent(int n)
    {
        if (n == parent[n])
            return n;

        return parent[n] = findparent(parent[n]);
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

    int kruskalsMST(int V, vector<vector<int>> &edges)
    {
        // Convert (u,v,wt) -> (wt,u,v)
        for (auto &it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            it[0] = wt;
            it[1] = u;
            it[2] = v;
        }

        // Sort by weight
        sort(edges.begin(), edges.end());

        disjointSet ds;
        ds.makeset(V);

        int netwt = 0;

        for (auto it : edges)
        {
            int wt = it[0];
            int u = it[1];
            int v = it[2];

            if (ds.findparent(u) != ds.findparent(v))
            {
                netwt += wt;
                ds.unionbysize(u, v);
            }
        }

        return netwt;
    }
};

int main()
{
    int V = 4;

    vector<vector<int>> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    Solution obj;

    cout << "Weight of MST = " << obj.kruskalsMST(V, edges);

    return 0;
}