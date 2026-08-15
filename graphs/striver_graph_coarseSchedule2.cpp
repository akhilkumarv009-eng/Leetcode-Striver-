#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        // Adjacency list
        vector<vector<int>> adj(numCourses);

        // Indegree array
        vector<int> indegree(numCourses, 0);

        // Build graph
        for (auto &it : prerequisites) {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        // Queue for nodes with indegree 0
        queue<int> q;

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

        // If all courses are processed, return the order
        if (topo.size() == numCourses)
            return topo;

        // Cycle exists
        return {};
    }
};