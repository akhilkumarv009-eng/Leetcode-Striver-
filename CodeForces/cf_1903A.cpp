#include <iostream>
#include <vector>
using namespace std;
int sorte(vector <int> & arr)
{
    for(int i=0;i<arr.size()-1;i++)
    {
        if(arr[i]>arr[i+1])
        return 0;
    }
    return 1;
}
int main()
{
    int t;
    cin >> t;
    for(int b=0;b<t;b++)
    {
        int n,k;
        cin >> n;
        cin >> k;
        vector <int> arr(n);
        for(int i=0;i<n ;i++)
        {
            cin >> arr[i];
        }
        int check=sorte(arr);
        if(check==1)
        cout << "YES"<<endl;
        else
        {
            if(k==1)
            cout << "NO"<<endl;
            else
            cout << "YES"<<endl;
        }

    }
}