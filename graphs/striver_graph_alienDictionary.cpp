#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> topoSort(int n,vector<int> adj[])
{
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
        {
            q.push(i); 
        }
    }
    vector<int> topo;
    while(!q.empty())
    {
        int node =q.front();
        q.pop();
        topo.push_back(node);
        for(auto it : adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
            {
                q.push(it);
            }
        }
    }
    return topo;


}
int main()
{
  int n,k;
  cin >> n >> k;
  string dic[n];
  for(int i=0;i<n;i++)
  {
    cin >> dic[i];
  }
  vector<int> adj[k];
  for(int i=0;i<n-1;i++)
  {
       string s1=dic[i];
       string s2=dic[i+1];
       int p1=0;
       int p2=0;
       int len = min(s1.size(), s2.size());

for(int j=0;j<len;j++)
{
    if(s1[j] != s2[j])
    {
        adj[s1[j]-'a'].push_back(s2[j]-'a');
        break;
    }
}
  }
  vector<int> topo = topoSort(k,adj);
  vector<char> ans;
  for(auto it : topo)
  {
    ans.push_back(it+'a');
  }
  for(auto it: ans)
  {
  cout << it << " ";
  }
}