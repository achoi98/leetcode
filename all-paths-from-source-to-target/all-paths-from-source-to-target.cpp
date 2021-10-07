class Solution {
public:
    int target;
    vector<vector<int>> result;
    vector<int> temp;
    
    void dfs(vector<vector<int>>& graph, int curr = 0) {
        temp.push_back(curr);
        if (curr == target) result.push_back(temp);
        else {
            for (auto& node: graph[curr]) {
                dfs(graph, node);
            }
        }
        temp.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        target = graph.size() - 1;
        dfs(graph);
        return result;
    }
};