class Solution {
public:
    
    // find the root node
    int find(int i, vector<int>& parent) {
        // if parent[i] < 0 it is the root node, return it
        // parent[i] = -1 in the beginning, indicates (-)1 node in the component
        // parent[i] < -1 when more nodes are connected, children nodes point to i
        if (parent[i] < 0) return i;
        else {
            return parent[i] = find(parent[i], parent);
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        // initialize to -1 to indicate each node is root node in the beginning
        vector<int> parent(s.size(), -1);
        
        // 2d vector to contain the connected components
        vector<vector<int>> components(s.size());
        
        // iterate through list of pairs and group connected indices
        for (auto &pair: pairs) {
            // root node of first index in pair
            int i = find(pair[0], parent);
            // root node of second index in pair
            int j = find(pair[1], parent);
            if (i != j) {
                // compare negative values to merge smaller into larger
                // parent[i] = -(number of nodes in component)
                if (-parent[i] < -parent[j]) {
                    swap(i, j);
                }
                parent[i] += parent[j];
                parent[j] = i;
            }
        }
        
        // iterate through string, push indices of same component together
        // components[find(i, parent)] = components[root index]
        for (auto i = 0; i < s.size(); i++) {
            components[find(i, parent)].push_back(i);
        }
        
        
        // iterate through the list of connected components
        for (auto &component: components) {
            string ss = "";
            // build the string with characters at the indices of this connected component
            for (auto index: component) {
                ss += s[index];
            }
            // sort the string
            sort(begin(ss), end(ss));
            for (auto i = 0; i < component.size(); i++) {
                s[component[i]] = ss[i];
            }
        }
        return s;
    }
};