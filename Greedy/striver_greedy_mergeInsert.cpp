#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        int i = 0;

        vector<int> temp = intervals[0];

        while (i < n) {
            if (intervals[i][0] <= temp[1]) {
                temp[1] = max(temp[1], intervals[i][1]);
            }
            else {
                ans.push_back(temp);
                temp = intervals[i];
            }
            i++;
        }

        ans.push_back(temp);

        return ans;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> intervals = {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18}
    };

    vector<vector<int>> ans = obj.merge(intervals);

    for (auto &v : ans) {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }

    return 0;
}