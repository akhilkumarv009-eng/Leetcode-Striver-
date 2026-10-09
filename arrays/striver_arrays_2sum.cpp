#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<pair<int,int>> num;
        int n = nums.size();

        for(int i = 0 ;i < n ; i++)
        {
            num.push_back({nums[i],i});
        }

        sort(num.begin(),num.end());

        int p =0;
        int q = n-1;
        while(p < q)
        {
            if(num[p].first + num[q].first == target)
            {
                return {num[p].second,num[q].second};
            }
            else if( num[p].first + num[q].first > target )
            {
                q--;
            }
            else
            {
                p++;
            }
        }

        return {};
        
    }
};