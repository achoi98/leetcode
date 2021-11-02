class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        queue<vector<int>> q;
        int fresh = 0;
        
        // push rotten oranges onto queue, count number of fresh oranges
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // rotten orange -> push coordinates to queue
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                // fresh orange -> increment count of fresh oranges
                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        
        // no fresh oranges at time 0
        if (fresh == 0) return 0;
        
        
        int count = -1; // -1 because count is incremented in the very first iteration
        vector<int> dir = {1, 0, -1, 0, 1};
        
        while (!q.empty()) {
            count++;    // +1 minute
            int size = q.size();
            for (int i = 0; i < size; i++) {
                vector<int> node = q.front();
                q.pop();
                for (int j = 0; j < 4; j++) {
                    int row = node[0] + dir[j];
                    int col = node[1] + dir[j + 1];
                    // proceed only if i, j are valid AND grid[i][j] is a fresh orange
                    if (col < 0 || row < 0 || col >= cols || row >= rows || grid[row][col] != 1) {
                        continue;
                    }
                    // change grid[i][j] to 2 to indicate that it is now rotten
                    grid[row][col] = 2;
                    // push the now rotten orange onto the queue
                    q.push({row, col});
                    // decrease number of fresh oranges by 1
                    fresh--;
                }
            }
        }
        
        return (fresh == 0) ? count : -1;
    }
};