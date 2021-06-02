class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> deg(numCourses, 0);
        for (auto &reqs : prerequisites) {
            adj[reqs[1]].push_back(reqs[0]);
            deg[reqs[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (deg[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            numCourses--;
            for (auto c : adj[curr]) {
                if (--deg[c] == 0) q.push(c);
            }
        }
        return numCourses == 0;
    }
};