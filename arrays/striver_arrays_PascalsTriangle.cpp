#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    vector<int> ansRow(int row) {
        long long col = 1;
        vector<int> ans;

        ans.push_back(col);

        for (int i = 1; i < row; i++) {
            col = col * (row - i);
            col = col / i;

            ans.push_back(col);
        }

        return ans;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> sol;

        for (int i = 1; i <= numRows; i++) {
            vector<int> ans = ansRow(i);
            sol.push_back(ans);
        }

        return sol;
    }
};

int main() {
    Solution obj;

    int numRows;
    cin >> numRows;

    vector<vector<int>> result = obj.generate(numRows);

    for (auto row : result) {
        for (auto value : row) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}