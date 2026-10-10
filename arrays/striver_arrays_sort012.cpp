#include <iostream>
#include <vector>
using namespace std;




class Solution {
public:
    void sortColors(vector<int>& nums) {

        int cnt1 = 0 ;
        int cnt2 = 0 ;
        int cnt3 = 0 ;

        int n = nums.size();

        for(int i = 0 ; i < n ; i++)
        {
            if( nums[i] == 0)
            cnt1++;
            else if(nums[i] == 1)
            cnt2++;
            else
            cnt3++;

        }
        int j = 0 ;
        for(int i = 0 ; i < cnt1 ;i++)
        {
            nums[j++] = 0;
        }
        for(int i = 0 ; i < cnt2 ;i++)
        {
            nums[j++] = 1;
        }
        for(int i = 0 ; i < cnt3 ;i++)
        {
            nums[j++] = 2;
        }
        
        
    }
};