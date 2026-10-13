#include <iostream>
#include <vector>
#include <map>
using namespace std;


class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        int n = nums.size();
        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i] < 0)nums[i]=nums[i]*(-1);
        }

        sort(nums.begin(),nums.end());
        long cnt = 0;
        long cnt2 = 0 ;
        int d = n/2;
        for(int i = 0 ; i < d ; i++)
        {
            cnt+= 1LL * (nums[i]*nums[i]);
        }
        for(int i = d ; i < n ; i++)
        {
            cnt2+= 1LL * (nums[i]*nums[i]);
        }

        return cnt2 - cnt;


        
    }
};