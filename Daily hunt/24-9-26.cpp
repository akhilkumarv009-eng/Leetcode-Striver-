#include <vector>
#include <numeric>
#include <algorithm>


using namespace std;

class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        
        for(int i = 0 ; i < nums.size();i++)
        {
           if(i < 10 && nums[i]==i)return i;

           int sum=0;
           int num = nums[i];
           while(num > 0)
           {
            sum = sum+num % 10;
            num = num/10;
           }
           if(sum == i)return i;
        }
        return -1;

    }
};