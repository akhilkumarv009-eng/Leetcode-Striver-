#include <iostream>
#include <vector>
#include<map>

using namespace std;
class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        if(n==0)return 0;
        int cout=0;
        int ans=0;
        for(int i = 0 ; i < n ;i++)
        {
           if(s[i]=='(')
           {
            cout++;
           }
           else if(s[i]==')')
           {
            cout--;
           }
           ans=max(ans,cout);
        }
        return ans;
    }
};