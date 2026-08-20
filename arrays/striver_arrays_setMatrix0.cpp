#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> rows;
        vector<int> columns;

        // Find all zero positions
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(matrix[i][j] == 0) {
                    rows.push_back(i);
                    columns.push_back(j);
                }
            }
        }

        // Make corresponding rows zero
        for(auto row : rows) {

            for(int j = 0; j < m; j++) {
                matrix[row][j] = 0;
            }
        }

        // Make corresponding columns zero
        for(auto col : columns) {

            for(int i = 0; i < n; i++) {
                matrix[i][col] = 0;
            }
        }
    }
};

int main() {

    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    Solution obj;

    obj.setZeroes(matrix);

    // Print matrix
    for(int i = 0; i < matrix.size(); i++) {

        for(int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}