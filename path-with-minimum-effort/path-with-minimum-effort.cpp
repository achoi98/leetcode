#define edge pair<int, pair<int, int>>
class Solution {
public:
    // directions to traverse adjacent cells
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        // priority queue of edges ordered in increasing difference
        priority_queue <edge, vector<edge>, greater<edge>> pq;
        // store max difference in heights from (0,0)
        vector<vector<int>> difference (rows, vector<int>(cols, INT_MAX));
        difference[0][0] = 0;
        pq.push({0, {0, 0}});
        // dijkstra
        while (!pq.empty()) {
            edge curr = pq.top();
            pq.pop();
            int diff = curr.first;
            int row = curr.second.first;
            int col = curr.second.second;
            int height = heights[row][col];
            if (row == rows - 1 && col == cols - 1) return diff;
            for (auto dir : directions) {
                int adjR = row + dir[0];
                int adjC = col + dir[1];
                // check if valid adjacent cell
                if (adjR < 0 || adjR >= rows || adjC < 0 || adjC >= cols) continue;
                // maximum between effort to reach current, and effort to reach adjacent
                int newDiff = max(diff, abs(height - heights[adjR][adjC]));
                
                if (newDiff < difference[adjR][adjC]) {
                    difference[adjR][adjC] = newDiff;
                    pq.push({newDiff, {adjR, adjC}});
                }
            }
        }
        return 0;
    }
};