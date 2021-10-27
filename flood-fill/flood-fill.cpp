class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) return image;
        vector<vector<int>> dirs {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        
        queue<vector<int>> q;
        
        int oldColor = image[sr][sc];
        image[sr][sc] = newColor;
        vector<int> start {sr, sc};
        q.push(start);
        while (!q.empty()) {
            vector<int> cell = q.front();
            q.pop();
            int r = cell[0];
            int c = cell[1];
            for (int i = 0; i < dirs.size(); i++) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];
                if (nr < 0 || nr >= image.size() || nc < 0 || nc >= image[0].size() || image[nr][nc] != oldColor) continue;
                else {
                    q.push({nr, nc});
                    image[nr][nc] = newColor;
                }
            }
        }
        
        return image;
    }
};