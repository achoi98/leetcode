class Solution {
public:
    // find function to determine parent of component
    // the parent of the component is the only node with a negative value in ds[]
    int find(vector<int>& ds, int i) {
        return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int sz = points.size();
        int result = 0;
        vector<int> ds(sz, -1);
        vector<array<int, 3>> edges;
        for (auto i = 0; i < sz; i++) {
            for (auto j = i + 1; j < sz; j++) {
                auto weight = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({weight, i, j});
            }
        }
        
        make_heap(begin(edges), end(edges), greater<array<int, 3>>());
        while (!edges.empty()) {
            pop_heap(begin(edges), end(edges), greater<array<int, 3>>());
            auto [dist, i, j] = edges.back();
            edges.pop_back();
            i = find(ds, i);
            j = find(ds, j);
            if (i != j) {
                result += dist;
                ds[i] += ds[j];
                ds[j] = i;
                if (ds[i] == -sz) break;
            }
        }
        return result;
    }
};