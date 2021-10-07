class Solution {
public:
    bool dfs(int current, int end, vector<vector<int>>& adj, vector<int>& visited) {
        if (current == end) return true;
        if (visited[current]) return false;
        visited[current] = 1;
        for (auto &it: adj[current]) {
            if (dfs(it, end, adj, visited)) return true;
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int>> adj(n);
        vector<int> visited(n, 0);
        for (auto &edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return dfs(start, end, adj, visited);
    }
};