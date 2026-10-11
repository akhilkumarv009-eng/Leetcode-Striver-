#include <iostream>
#include <vector>
#include <map>
using namespace std;


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        map<int,int> mp;
        vector<int> ans;

        for(int i = 0 ; i < n ; i++)
        {
            mp[nums[i]]++;
        }

        int floor = n /3;

        for(auto it : mp)
        {
            if(it.second > floor)
            ans.push_back(it.first);
        }

        return ans;

    }
};