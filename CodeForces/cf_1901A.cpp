#include <iostream>
#include <vector>
using namespace std;
int diff(int a,int b)
{
    if(a>b)
    return a-b;
    else
    return b-a;
}
int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        int n;
        int x;
        cin >> n >> x;
        vector <int> arr(n+2);
        for(int j=1;j<=n;j++)
        {
            cin >> arr[j];
        }
        arr[0]=0;
        arr[n+1]=x;
        int ans=-1;
        for(int k=0;k<n+1;k++)
        {
            int ans2=diff(arr[k+1],arr[k]);
            if(ans<ans2)
            {
                ans=ans2;
            }
        }
        if(ans<(2*(arr[n+1]-arr[n])))
        {
            ans=2*(arr[n+1]-arr[n]);
        }
        cout << ans<< endl;

    }
}