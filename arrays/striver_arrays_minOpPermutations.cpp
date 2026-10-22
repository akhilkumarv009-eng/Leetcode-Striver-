#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        int n = nums.size();
        int zero_idx = -1;
        
        // Find where 0 is located
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                zero_idx = i;
                break;
            }
        }
        
        // Helper function to check if the sequence is valid given a step direction (+1 or -1)
        auto check = [&](int step) {
            for (int i = 1; i < n; ++i) {
                int prev = (zero_idx + (i - 1) * step % n + n) % n;
                int curr = (zero_idx + i * step % n + n) % n;
                if (nums[prev] > nums[curr]) return false;
            }
            return true;
        };
        
        const int INF = 1e9;
        int ans = INF;
        
        // Case 1: Sequence steps forward (+1)
        if (check(1)) {
            ans = std::min(ans, zero_idx);          // Just left rotations
            ans = std::min(ans, n - zero_idx + 2);  // Reverse -> Rotations -> Reverse
        }
        
        // Case 2: Sequence steps backward (-1)
        if (check(-1)) {
            ans = std::min(ans, zero_idx + 2);      // Left rotations -> Reverse
            ans = std::min(ans, n - zero_idx);      // Reverse -> Left rotations
        }
        
        return (ans == INF) ? -1 : ans;
    }
};
