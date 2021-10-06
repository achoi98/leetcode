class Solution {
public:
    // find the root of a given node optimized with path compression
    int find(int i, vector<int>& parent) {
        while (parent[i] != i) {
            /*
            below is the same as: parent[i] = parent[parent[i]]; i = parent[i];
            */
            i = parent[i] = parent[parent[i]];
        }
        return i;
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        // 1. check for cycles
        // 2. check every node is connected
        if (edges.size() != n - 1) return false;
        vector<int> parent(n);
        vector<int> size(n, 1);
        iota(parent.begin(), parent.end(), 0);
        for (auto &edge: edges) {
            int rootA = find(edge[0], parent);
            int rootB = find(edge[1], parent);
            if (rootA == rootB) return false;               // if rootA==rootB there is a cycle
            if (size[rootA] > size[rootB]) {
                parent[rootA] = rootB;
                size[rootB] += size[rootA];
            }
            else {
                parent[rootB] = rootA;
                size[rootA] += size[rootB];
            }
            n--;
        }
        return (n == 1);                                   // return true if there is one component
    }
};