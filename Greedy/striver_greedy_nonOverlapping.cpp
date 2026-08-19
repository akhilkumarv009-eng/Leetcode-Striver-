#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct item
{
    int start;
    int end;
};

bool comp(item a, item b)
{
    return a.end < b.end;
}

int main()
{
    int n;
    cin >> n;

    vector<item> arr(n);

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].start >> arr[i].end;
    }

    sort(arr.begin(), arr.end(), comp);

    int cnt = 1;
    int lastEnd = arr[0].end;

    for(int i = 1; i < n; i++)
    {
        if(arr[i].start >= lastEnd)
        {
            cnt++;
            lastEnd = arr[i].end;
        }
    }

    cout << n - cnt << endl;

    return 0;
}