#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> kahns(vector<int> adj[],int n)
{
    vector<int> ans;
    queue <int> q;
    vector<int> indegree(n,0);
    for(int i=0;i<n;i++)
    {
        for(auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
       for(auto it : adj[node])
       {
         indegree[it]--;
         if(indegree[it]==0)
         q.push(it);
       }
       
    }
    return ans;
}
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> adj[n];
    int u,v;
    for(int i=0;i<m;i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> ans=kahns(adj,n);
    for(auto it : ans)
    cout << it << " ";
}