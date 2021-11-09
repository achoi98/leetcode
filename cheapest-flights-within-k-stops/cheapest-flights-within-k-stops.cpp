class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> distances(2, vector<int>(n));
        fill(distances[0].begin(), distances[0].end(), INT_MAX);
        fill(distances[1].begin(), distances[1].end(), INT_MAX);
        distances[0][src] = distances[1][src] = 0;
        
        // k + 1 iterations (at most k stops, so at most k + 1 edges)
        for (int i = 0; i < k + 1; i++) {
            for (auto edge : flights) {
                int s = edge[0], d = edge[1], wUV = edge[2];
                
                // i%2 = 0 when i = 0,2,4,...
                int dU = distances[1 - i%2][s];
                int dV = distances[i%2][d];
                
                if (dU < INT_MAX && dU + wUV < dV) {
                    distances[i%2][d] = dU + wUV;
                }
            }
        }
        
        return (distances[k%2][dst] < INT_MAX) ? distances[k%2][dst] : -1;
    }
};