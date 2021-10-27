class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dirs {{1, 0}, {-1, 0}, {0, 1}, {0,  -1}};
        
        int max = 0;
        
        queue<vector<int>> q;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] != 1) continue;
                q.push({i, j});
                int curr = 0;
                grid[i][j] = 0;
                while (!q.empty()) {
                    curr++;
                    vector<int> n = q.front();
                    q.pop();
                    int r = n[0];
                    int c = n[1];
                    for (int k = 0; k < dirs.size(); k++) {
                        int nr = r + dirs[k][0];
                        int nc = c + dirs[k][1];
                        if (nr < 0 || nr >= rows || nc < 0 || nc >= cols || grid[nr][nc] != 1) continue;
                        q.push({nr, nc});
                        grid[nr][nc] = 0;
                    }
                }
                if (curr > max) max = curr;
            }
        }
        return max;
    }
};