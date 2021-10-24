class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        queue<vector<int>> q;
        int fresh = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        if (fresh == 0) return 0;
        
        int count = -1;
        vector<int> dir = {1, 0, -1, 0, 1};
        
        while (!q.empty()) {
            count++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                vector<int> node = q.front();
                q.pop();
                for (int j = 0; j < 4; j++) {
                    int row = node[0] + dir[j];
                    int col = node[1] + dir[j + 1];
                    if (col < 0 || row < 0 || col >= cols || row >= rows || grid[row][col] != 1) {
                        continue;
                    }
                    grid[row][col] = 2;
                    q.push({row, col});
                    fresh--;
                }
            }
        }
        
        return (fresh == 0) ? count : -1;
    }
};