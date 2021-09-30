class Solution {
public:
    vector<int> root;
    
    int find(int x) {
        if (root[x] == -1) return x;
        return root[x] = find(root[x]);
    }
    
    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            root[rootY] = rootX;
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        if (isConnected.empty()) return 0;
        int sz = isConnected.size();
        root = vector<int> (sz, -1);
        
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                if (isConnected[i][j]) {
                    unionSet(i, j);
                }
            }
        }
        int count = 0;
        for (int i = 0; i < sz; i++) {
            if (root[i] == -1) count++;
        }
        return count;
    }
    
};