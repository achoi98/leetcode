class Solution {
public:
    vector<vector<int>> directions
    {
        {-1, -1},
        {-1, 0},
        {-1, 1},
        {0, -1},
        {0, 1},
        {1, -1},
        {1, 0},
        {1, 1}
    };
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // check start and end cells are valid
        if (grid.empty() || grid[0][0] || grid[grid.size() - 1][grid.size() - 1]) 
            return -1;
        
        // BFS setup
        queue<pair<int, int>> q;
        pair<int, int> root = make_pair(0, 0);
        q.push(root);
        grid[0][0] = 1;
        
        while(!q.empty()) {
            pair<int, int> cell = q.front();
            q.pop();
            int row = cell.first;
            int col = cell.second;
            int distance = grid[row][col];
            if (row == grid.size() - 1 && col == grid.size() - 1) {
                cout << "row:" << row << "\tcol:" << col << endl;
                cout << "distance:" << distance << endl;
                return distance;
            }
            for (int i = 0; i < directions.size(); i++) {
                int newRow = row + directions[i][0];
                int newCol = col + directions[i][1];
                if (newRow < 0 || newCol < 0 || newRow >= grid.size() || newCol >= grid.size() || grid[newRow][newCol] != 0) {
                    continue;
                }
                pair<int, int> neighbor = make_pair(newRow, newCol);
                q.push(neighbor);
                grid[newRow][newCol] = distance + 1;
            }
        }
        return -1;
    }
};