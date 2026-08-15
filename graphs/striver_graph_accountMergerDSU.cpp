#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

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
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();

        dsu ds;
        ds.makeset(n);

        unordered_map<string, int> mp;

        // Merge accounts having common emails
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string mail = accounts[i][j];

                if (mp.find(mail) == mp.end())
                {
                    mp[mail] = i;
                }
                else
                {
                    ds.unionbysize(i, mp[mail]);
                }
            }
        }

        // Store emails according to their ultimate parent
        vector<string> mergedMail[n];

        for (auto it : mp)
        {
            string mail = it.first;
            int node = it.second;

            int parent = ds.findparent(node);
            mergedMail[parent].push_back(mail);
        }

        // Prepare answer
        vector<vector<string>> ans;

        for (int i = 0; i < n; i++)
        {
            if (mergedMail[i].empty())
                continue;

            sort(mergedMail[i].begin(), mergedMail[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for (auto mail : mergedMail[i])
            {
                temp.push_back(mail);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    vector<vector<string>> accounts = {
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnnybravo@mail.com"}};

    vector<vector<string>> ans = obj.accountsMerge(accounts);

    for (auto account : ans)
    {
        for (auto s : account)
        {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}