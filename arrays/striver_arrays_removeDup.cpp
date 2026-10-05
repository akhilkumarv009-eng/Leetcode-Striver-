#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        map<int,int> mp;
        int count = 0 ;
        for(int i = 0 ; i < n ; i ++)
        {
           if(mp.find(nums[i])==mp.end())
           {
              count++;
              mp[nums[i]]=1;
           }
        }
        int j = 0;
        for(auto it : mp)
        {
            nums[j++]=it.first;
        }

       

        return count;
        
    }
};