#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> insertInterval(vector<vector<int>>& intervals,
                                   vector<int>& newInterval) {
    vector<vector<int>> ans;
    int n = intervals.size();
    int i = 0;

    // Add intervals before newInterval
    while (i < n && intervals[i][1] < newInterval[0]) {
        ans.push_back(intervals[i]);
        i++;
    }

    // Merge overlapping intervals
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }

    ans.push_back(newInterval);

    // Add remaining intervals
    while (i < n) {
        ans.push_back(intervals[i]);
        i++;
    }

    return ans;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};

    vector<vector<int>> result = insertInterval(intervals, newInterval);

    for (auto &interval : result) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }

    cout << endl;
    return 0;
}