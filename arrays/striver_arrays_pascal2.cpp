#include <iostream>
#include <vector>
using namespace std;




class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> ans;
        ans.push_back(1);
        long long an = 1;
        int n = rowIndex+1;
        for(int i = 1 ; i < n ;i++)
        {
              an = an * (n - i);
              an = an / i;
              ans.push_back(an);
        }
        return ans;
    }
};