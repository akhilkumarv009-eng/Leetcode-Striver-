#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

// Structure to reconstruct our path
struct State {
    int d;
    int b;
};

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    // dp[i][d][b] -> we can optimize space to dp[d][b]
    // dp[d][b] stores the minimum LRBS length with 'd' deletions and balance 'b'
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));
    
    // To reconstruct path, we save the full parent states: parent[i][d][b]
    // choice: 0 = Deleted, 1 = Kept
    vector<vector<vector<int>>> choice(n + 1, vector<vector<int>>(k + 1, vector<int>(n + 1, -1)));
    vector<vector<vector<State>>> parent(n + 1, vector<vector<State>>(k + 1, vector<State>(n + 1, { -1, -1 })));

    dp[0][0] = 0;

    for (int i = 0; i < n; ++i) {
        // Next DP state array
        vector<vector<int>> next_dp(k + 1, vector<vector<int>>::value_type(n + 1, INF));

        for (int d = 0; d <= min(i, k); ++d) {
            for (int b = 0; b <= i - d; ++b) {
                if (dp[d][b] == INF) continue;

                // Option 1: Delete s[i]
                if (d + 1 <= k) {
                    if (dp[d][b] < next_dp[d + 1][b]) {
                        next_dp[d + 1][b] = dp[d][b];
                        choice[i + 1][d + 1][b] = 0;
                        parent[i + 1][d + 1][b] = { d, b };
                    }
                }

                // Option 2: Keep s[i]
                if (s[i] == '(') {
                    if (b + 1 <= n) {
                        if (dp[d][b] < next_dp[d][b + 1]) {
                            next_dp[d][b + 1] = dp[d][b];
                            choice[i + 1][d][b + 1] = 1;
                            parent[i + 1][d][b + 1] = { d, b };
                        }
                    }
                } else { // s[i] == ')'
                    if (b > 0) {
                        // Regular bracket match found! LRBS increases by 2.
                        if (dp[d][b] + 2 < next_dp[d][b - 1]) {
                            next_dp[d][b - 1] = dp[d][b] + 2;
                            choice[i + 1][d][b - 1] = 1;
                            parent[i + 1][d][b - 1] = { d, b };
                        }
                    } else {
                        // Unmatched ')', cost doesn't change
                        if (dp[d][b] < next_dp[d][0]) {
                            next_dp[d][0] = dp[d][b];
                            choice[i + 1][d][0] = 1;
                            parent[i + 1][d][0] = { d, b };
                        }
                    }
                }
            }
        }
        dp = move(next_dp);
    }

    // Find the minimum cost among all valid terminal states (d <= k)
    int min_cost = INF;
    int best_d = -1, best_b = -1;

    for (int d = 0; d <= k; ++d) {
        for (int b = 0; b <= n; ++b) {
            if (dp[d][b] < min_cost) {
                min_cost = dp[d][b];
                best_d = d;
                best_b = b;
            }
        }
    }

    // Backtrack to build the binary string
    string ans = "";
    int curr_d = best_d;
    int curr_b = best_b;

    for (int i = n; i > 0; --i) {
        int ch = choice[i][curr_d][curr_b];
        if (ch == 0) {
            ans += '1'; // 1 indicates deletion
        } else {
            ans += '0'; // 0 indicates kept
        }
        State p = parent[i][curr_d][curr_b];
        curr_d = p.d;
        curr_b = p.b;
    }

    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
}

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}