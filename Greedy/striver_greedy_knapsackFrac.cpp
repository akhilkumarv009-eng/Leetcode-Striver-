#include <iostream>
#include <algorithm>
using namespace std;
struct item
{
    double value;
    double weight;
};
bool compare(item a ,item b)
{
    return (a.value/a.weight > b.value/b.weight);
   
}
int main()
{
   int n;
   cin >> n;
   vector<item> arr(n);
   int w; 
   cin >> w;
   for(int i = 0 ; i < n ; i ++)
   {
    cin >> arr[i].value >> arr[i].weight ;
   }
   sort(arr.begin(),arr.end(),compare);

   int ans=0;
   int tw=0;

   for(int i =0 ; i < n ; i ++ )
   {
    if(tw + arr[i].weight <= w)
    {
        ans=ans+arr[i].value;
        tw+=arr[i].weight;
    }
    else
    {
        float k = ((w-tw)/arr[i].weight) * arr[i].value;
        ans+=k;
        break;
    }
   }
   cout << ans;
}