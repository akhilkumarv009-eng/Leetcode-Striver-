  #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int cnt = 0;
        int p1 = 0;
        int p2 = 0;

        while (p1 < g.size() && p2 < s.size())
        {
            if (g[p1] <= s[p2])
            {
                cnt++;
                p1++;
            }

            p2++;
        }

        return cnt;
    }
};

int main()
{
    Solution obj;

    int n, m;

    cin >> n;

    vector<int> g(n);
    for (int i = 0; i < n; i++)
    {
        cin >> g[i];
    }

    cin >> m;

    vector<int> s(m);
    for (int i = 0; i < m; i++)
    {
        cin >> s[i];
    }

    cout << obj.findContentChildren(g, s);

    return 0;
}