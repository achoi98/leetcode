class Solution {
public:
    static bool compare(vector<int>& v1, vector<int>& v2) {
        return v1[0] < v2[0];
    }
    
    int find(int i, vector<int>& parent) {
        while (parent[i] != i) {
            i = parent[i] = parent[parent[i]];
        }
        return i;
    }
    
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end(), compare);
        vector<int> parent(n);
        vector<int> size(n, 1);
        iota(parent.begin(), parent.end(), 0);
        for (auto &log: logs) {
            int personA = find(log[1], parent);
            int personB = find(log[2], parent);
            if (personA != personB) {
                n--;
                if (size[personA] < size[personB]) {
                    parent[personA] = personB;
                    size[personB] += size[personA];
                }
                else {
                    parent[personB] = personA;
                    size[personA] += size[personB];
                }
            }
            if (n == 1) return log[0];
        }
        return -1;
    }
};