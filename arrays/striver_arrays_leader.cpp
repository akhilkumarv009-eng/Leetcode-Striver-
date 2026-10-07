#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr={10,22,12,3,0,6};

    int maxi=INT_MIN;
    int n = arr.size();

    vector<int> ans ;

    for(int i = n-1 ;i >=0; i--)
    {
        if(arr[i] > maxi)
        {
            maxi = arr[i];
            ans.push_back(arr[i]);
        }
    }

    for(auto it : ans )
    {
        cout << it << " ";
    }

}