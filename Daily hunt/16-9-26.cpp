#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long MOD = 1000000007;

        vector<vector<long long>> dp(n, vector<long long>(k + 1, 0));

        // 0 segments = 1 way
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        for (int j = 1; j <= k; j++) {
            long long sum = 0;

            for (int i = 1; i < n; i++) {

                // Ways to create a new segment ending at i
                sum = (sum + dp[i - 1][j - 1]) % MOD;

                // Either don't end a segment at i,
                // or use one of the possibilities in sum
                dp[i][j] = (dp[i - 1][j] + sum) % MOD;
            }
        }

        return dp[n - 1][k];
    }
};