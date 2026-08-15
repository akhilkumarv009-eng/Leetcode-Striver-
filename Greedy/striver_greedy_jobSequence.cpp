#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct job
{
    int deadline;
    int profit;
    int index;
};
bool comp(job a,job b)
{
    return a.profit > b.profit;
}
int main()
{
  int n;
  cin >> n;
  
  vector<job> arr(n);

  for(int i = 0 ; i < n ; i ++)
  {
    cin >> arr[i].index >> arr[i].deadline >> arr[i].profit;
  }

  sort(arr.begin(),arr.end(),comp);

  int m =0;
  for(int i = 0; i < n ; i ++)
  {
    m=max(m,arr[i].deadline);
  }

  vector<int> hash(m+1,-1);

 int cnt=0;
 int maxprofit=0;

  for(int i = 0 ; i < n ; i++)
  {
      for(int j=arr[i].deadline ; j>=1 ; j--)
      {
          if(hash[j]==-1)
          {
            hash[j]=arr[i].index;
            maxprofit+=arr[i].profit;
            cnt++;
            break;
          }
      }
  }

  cout << maxprofit;



}