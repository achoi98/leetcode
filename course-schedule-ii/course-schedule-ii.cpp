class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order;                                      // order of courses
        vector<vector<int>> adj(numCourses, vector<int>());     // adjacency matrix
        vector<int> deg(numCourses, 0);                         // in-degree counter
        
        for (auto &reqs : prerequisites) {
            adj[reqs[1]].push_back(reqs[0]);
            deg[reqs[0]]++;
        }
        queue<int> q;                                           // course queue
        for (int i = 0; i < numCourses; i++) {
            if (deg[i] == 0) q.push(i);                         // if in-degree of node is 0 add to queue
        }
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            order.push_back(curr);
            numCourses--;
            for (auto c : adj[curr]) {
                if (--deg[c] == 0) q.push(c);
            }
        }
        
        return (numCourses == 0) ? order : vector<int>();
    }
};