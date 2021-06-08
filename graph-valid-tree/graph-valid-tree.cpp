class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        vector<int> nodes(n, 0);
        for (int i = 0; i < n; i++) {
            nodes[i] = i;
        }
        for (int i = 0; i < edges.size(); i++) {
            int first = edges[i][0];
            int second = edges[i][1];
            while (nodes[first] != first) {
                first = nodes[first];
            }
            while (nodes[second] != second) {
                second = nodes[second];
            }
            if (first == second) return false;
            nodes[second] = first;
        }
        return true;
        
    }
};