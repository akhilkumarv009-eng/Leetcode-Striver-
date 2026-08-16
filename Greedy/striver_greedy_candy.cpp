#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {

        int n = ratings.size();

        int i = 1;
        int sum = 1;

        while (i < n) {

            if (ratings[i] == ratings[i - 1]) {
                sum += 1;
                i++;
                continue;
            }

            int up = 1;
            while (i < n && ratings[i] > ratings[i - 1]) {
                up++;
                sum += up;
                i++;
            }

            int down = 1;
            while (i < n && ratings[i] < ratings[i - 1]) {
                sum += down;
                down++;
                i++;
            }

            if (down > up) {
                sum += (down - up);
            }
        }

        return sum;
    }
};

int main() {

    int n;
    cin >> n;

    vector<int> ratings(n);

    for (int i = 0; i < n; i++) {
        cin >> ratings[i];
    }

    Solution obj;

    cout << obj.candy(ratings) << endl;

    return 0;
}