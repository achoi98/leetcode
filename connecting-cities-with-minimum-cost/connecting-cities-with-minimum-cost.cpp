class Solution {
public:
    int find(vector<int>& ds, int i) {
        return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
    }
    
    int minimumCost(int n, vector<vector<int>>& connections) {
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
        for (auto c: connections) {
            pq.push({c[2], c[0], c[1]});
        }
        
        vector<int> ds(n + 1, -1);
        int total = 0;
        int edges = 0;
        while (!pq.empty()) {
            int city1 = pq.top()[1];
            int city2 = pq.top()[2];
            int cost = pq.top()[0];
            pq.pop();
            int p1 = find(ds, city1);
            int p2 = find(ds, city2);
            if (p1 != p2) {
                total += cost;
                ds[p1] += ds[p2];
                ds[p2] = p1;
                edges++;
            }
        }
        return (edges == n - 1) ? total : -1;
    }
};