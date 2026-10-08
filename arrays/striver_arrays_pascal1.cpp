#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:

    vector<int> rowc(int n)
    {
        vector<int> ans;
        ans.push_back(1);
        long long an = 1;
        for(int i = 1 ; i <n ; i++)
        {
            an = an * (n - i);
            an = an / i ; 

            ans.push_back(an);
        }

        return ans;
    }
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans;
        for(int i = 1 ; i <= numRows ; i++)
        { 
            vector<int> s = rowc(i);
            ans.push_back(s);
        }

        return ans ;        
    }
};