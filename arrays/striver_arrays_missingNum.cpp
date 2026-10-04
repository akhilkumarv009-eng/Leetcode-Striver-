#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n*(n+1))/2;
        int count = 0 ;
        for(int i = 0 ; i < n ; i ++)
        {
            count+=nums[i];
        }
        return sum - count;
        
    }
};