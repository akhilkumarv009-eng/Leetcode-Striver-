#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mp;
        for(auto it : nums)
        {
            mp[it]++;
        }
        int cnt = 0;
        int element;
        for(auto it : mp)
        {
            if(it.second > cnt)
            {
                cnt = it.second;
                element = it.first;
            }
        }
        return element;
    }
};