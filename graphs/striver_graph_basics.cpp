#include <iostream>
#include <vector>
using namespace std;
int main()
{
   int n,m;
   cin >> n >> m;
   vector <int> arr[n+1];
   int u,v;
   for(int i=0;i<m;i++)
   {
     u=v=0;
     cin >> u >> v ;
     arr[u].push_back(v);
   }
}