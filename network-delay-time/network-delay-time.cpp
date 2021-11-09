class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // times[i] = (ui,vi,wi)
        // k = source node
        // n = number of nodes
        
        // build graph
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto edge : times) {
            int from = edge[0], to = edge[1], cost = edge[2];
            graph[from].push_back(make_pair(cost, to));
        }
        
        vector<int> d(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        d[k] = 0;
        pq.push(make_pair(0, k));
        while (!pq.empty()) {
            pair<int, int> node = pq.top();
            int u = node.second;
            int d_u = d[u];
            pq.pop();
            // relax edges
            for (auto neighbor : graph[u]) {
                int w_uv = neighbor.first;
                int v = neighbor.second;
                int d_v = d_u + w_uv;
                if (d_v < d[v]) {
                    d[v] = d_v;
                    pq.push(make_pair(d_v, v));
                }
                
            }
        }
        int max_t = INT_MIN;
        for (int i = 1; i < d.size(); i++) {
            if (max_t < d[i]) {
                max_t = d[i];
            }
        }
        
        return max_t == INT_MAX ? -1 : max_t;
    }
};