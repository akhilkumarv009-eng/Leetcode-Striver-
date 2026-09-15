#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        vector<int> dp(n + 1, 0);
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Check all substrings for palindrome
        for (int len = 1; len <= n; len++) {
            for (int l = 0; l + len <= n; l++) {

                int r = l + len - 1;

                if (s[l] == s[r] &&
                    (len <= 2 || pal[l + 1][r - 1])) {
                    pal[l][r] = true;
                }
            }
        }

        // DP
        for (int i = 1; i <= n; i++) {

            // Don't take a palindrome ending here
            dp[i] = dp[i - 1];

            // Take palindrome s[j ... i-1]
            for (int j = 0; j < i; j++) {

                if (i - j >= k && pal[j][i - 1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n];
    }
};

int main() {
    Solution obj;

    string s;
    int k;

    cin >> s;
    cin >> k;

    cout << obj.maxPalindromes(s, k) << endl;

    return 0;
}