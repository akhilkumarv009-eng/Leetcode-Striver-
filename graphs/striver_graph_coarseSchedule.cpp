#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> indegree(numCourses, 0);
        vector<int> adj[numCourses];

        // Build graph and indegree array
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        queue<int> q;

        // Push all nodes with indegree 0
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;

        // Kahn's Algorithm
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for (auto it : adj[node]) {
                indegree[it]--;

                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        return topo.size() == numCourses;
    }
};

int main() {
    Solution obj;

    int numCourses = 4;

    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 1},
        {3, 2}
    };

    if (obj.canFinish(numCourses, prerequisites))
        cout << "Yes, all courses can be finished." << endl;
    else
        cout << "No, cycle exists. Cannot finish all courses." << endl;

    return 0;
}