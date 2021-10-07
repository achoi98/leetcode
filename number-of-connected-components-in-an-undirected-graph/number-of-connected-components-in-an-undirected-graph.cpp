class Solution {
public:
    int find(int i, vector<int>& parent) {
        while (parent[i] != i) {
            i = parent[i] = parent[parent[i]];
        }
        return i;
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        vector<int> size(n, 1);
        iota(parent.begin(), parent.end(), 0);
        for (auto &edge: edges) {
            int rootA = find(edge[0], parent);
            int rootB = find(edge[1], parent);
            if (rootA != rootB) {
                n--;
                if (size[rootA] < size[rootB]) {
                    parent[rootA] = rootB;
                    size[rootB] += size[rootA];
                }
                else {
                    parent[rootB] = rootA;
                    size[rootA] += size[rootB];
                }
            }
        }
        return n;
    }
};