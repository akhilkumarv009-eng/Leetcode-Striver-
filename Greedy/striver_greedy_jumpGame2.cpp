#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int l = 0, r = 0;
        int n = nums.size();

        while (r < n - 1) {
            int farthest = 0;

            for (int i = l; i <= r; i++) {
                farthest = max(farthest, i + nums[i]);
            }

            l = r + 1;
            r = farthest;
            jumps++;
        }

        return jumps;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {2, 3, 1, 1, 4};

    cout << "Minimum Jumps: " << obj.jump(nums) << endl;

    return 0;
}