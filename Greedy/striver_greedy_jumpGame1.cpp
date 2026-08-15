#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maximum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (maximum >= i) {
                maximum = max(maximum, i + nums[i]);
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {2, 3, 1, 1, 4};

    if (obj.canJump(nums))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}