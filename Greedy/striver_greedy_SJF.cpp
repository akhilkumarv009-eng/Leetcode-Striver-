#include <iostream>
#include <vector>
using namespace std; 
int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0 ; i < n ; i ++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(),arr.end());

    int wt=0;
    int time=0;

    for(int i = 0 ; i < n ; i ++)
    {
       wt+=time;
       time+=arr[i];
    }
    cout << wt/n;

}