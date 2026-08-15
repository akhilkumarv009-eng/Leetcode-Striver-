#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int n = image.size();
        int m = image[0].size();

        int prev = image[sr][sc];

        if (prev == color)
            return image;

        queue<pair<int, int>> q;
        q.push({sr, sc});

        image[sr][sc] = color;

        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            // Up
            if (i - 1 >= 0 && image[i - 1][j] == prev) {
                image[i - 1][j] = color;
                q.push({i - 1, j});
            }

            // Left
            if (j - 1 >= 0 && image[i][j - 1] == prev) {
                image[i][j - 1] = color;
                q.push({i, j - 1});
            }

            // Down
            if (i + 1 < n && image[i + 1][j] == prev) {
                image[i + 1][j] = color;
                q.push({i + 1, j});
            }

            // Right
            if (j + 1 < m && image[i][j + 1] == prev) {
                image[i][j + 1] = color;
                q.push({i, j + 1});
            }
        }

        return image;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> image(n, vector<int>(m));

    // Input the image
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> image[i][j];
        }
    }

    int sr, sc, color;
    cin >> sr >> sc >> color;

    Solution obj;
    vector<vector<int>> ans = obj.floodFill(image, sr, sc, color);

    // Output the modified image
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}