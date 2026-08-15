#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minSteps(vector<int>& arr, int start, int end) {

        if (start == end)
            return 0;

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<int> dist(1000, 1e9);

        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {

            int ans = pq.top().first;
            int num = pq.top().second;
            pq.pop();

            // Ignore outdated entries
            if (ans > dist[num])
                continue;

            for (auto it : arr) {

                int num2 = (num * it) % 1000;

                if (ans + 1 < dist[num2]) {

                    dist[num2] = ans + 1;

                    if (num2 == end)
                        return ans + 1;

                    pq.push({ans + 1, num2});
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution obj;

    vector<int> arr = {2, 5, 7};
    int start = 3;
    int end = 30;

    cout << obj.minSteps(arr, start, end);

    return 0;
} 