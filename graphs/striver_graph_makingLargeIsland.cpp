#include <iostream>
#include <vector>
#include <set>

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

    int findparent(int n)
    {
        if(n == parent[n])
            return n;

        return parent[n] = findparent(parent[n]);
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

    int largestIsland(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        dsu dv;

        // Create DSU for all cells
        dv.makeset(n * m);

        int count = 0;

        // STEP 1: Connect all existing 1s
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    // UP
                    if(i - 1 >= 0 && grid[i-1][j] == 1)
                    {
                        dv.unionbysize(
                            m * i + j,
                            m * (i-1) + j
                        );
                    }

                    // LEFT
                    if(j - 1 >= 0 && grid[i][j-1] == 1)
                    {
                        dv.unionbysize(
                            m * i + j,
                            m * i + j - 1
                        );
                    }

                    // DOWN
                    if(i + 1 < n && grid[i+1][j] == 1)
                    {
                        dv.unionbysize(
                            m * i + j,
                            m * (i+1) + j
                        );
                    }

                    // RIGHT
                    if(j + 1 < m && grid[i][j+1] == 1)
                    {
                        dv.unionbysize(
                            m * i + j,
                            m * i + j + 1
                        );
                    }
                }
                else
                {
                    count++;
                }
            }
        }

        // If there are no zeroes,
        // the entire grid is already one island.
        if(count == 0)
            return n * m;


        int ans = 0;

        // STEP 2: Try converting every 0 into 1
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 0)
                {
                    set<int> st;

                    // UP
                    if(i - 1 >= 0 && grid[i-1][j] == 1)
                    {
                        int index = m * (i-1) + j;

                        int pr = dv.findparent(index);

                        st.insert(pr);
                    }

                    // LEFT
                    if(j - 1 >= 0 && grid[i][j-1] == 1)
                    {
                        int index = m * i + j - 1;

                        int pr = dv.findparent(index);

                        st.insert(pr);
                    }

                    // DOWN
                    if(i + 1 < n && grid[i+1][j] == 1)
                    {
                        int index = m * (i+1) + j;

                        int pr = dv.findparent(index);

                        st.insert(pr);
                    }

                    // RIGHT
                    if(j + 1 < m && grid[i][j+1] == 1)
                    {
                        int index = m * i + j + 1;

                        int pr = dv.findparent(index);

                        st.insert(pr);
                    }


                    // Current 0 becomes 1
                    int cnt2 = 1;

                    // Add sizes of all unique islands
                    for(auto it : st)
                    {
                        cnt2 += dv.Size[it];
                    }

                    ans = max(ans, cnt2);
                }
            }
        }

        return ans;
    }
};