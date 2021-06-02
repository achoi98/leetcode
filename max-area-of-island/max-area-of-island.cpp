class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> vec(m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    count = max(count, traverse(i, j, m, n, grid));
                    }
                }
            }
        return count;
        }
    
    int traverse(int i, int j, int m, int n, vector<vector<int>>& grid) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) return 0;
        else {
            grid[i][j] = -1;
            return 1 + traverse(i - 1, j, m, n, grid) + traverse(i + 1, j, m, n, grid) + traverse(i, j - 1, m, n, grid) + traverse(i, j + 1, m, n, grid);
        }
    }
};