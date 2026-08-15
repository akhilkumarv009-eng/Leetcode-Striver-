#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> ans;

        // Block 1
        for (int i = 1; i <= n; i++) ans.push_back(i);

        // Block 2
        for (int i = 1; i <= n; i++) ans.push_back(i);

        // Block 3
        vector<int> rev;
        for (int i = n; i >= 1; i--) rev.push_back(i);

        if (n % 2 == 1) {
            int m = (n + 1) / 2;      // 1-based
            swap(rev[m - 1], rev[m]);
        }

        for (int x : rev) ans.push_back(x);

        // Block 4
        for (int i = 1; i <= n; i++) ans.push_back(i);

        for (int i = 0; i < 4 * n; i++) {
            if (i) cout << ' ';
            cout << ans[i];
        }
        cout << '\n';
    }

    return 0;
}