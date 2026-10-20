#include <iostream>
#include <vector>
#include <map>
using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        int pref =1;
        int sif = 1;
        int ans = INT_MIN;

        for(int i = 0 ; i < n ;i++)
        {
           if(pref == 0)pref = 1;
           if(sif == 0)sif = 1;

           pref = pref * nums[i];
           sif = sif * nums[n-i-1];

           ans = max(ans,max(pref,sif));

        }
        return ans;
    }
};