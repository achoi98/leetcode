class Solution {
public:
    int firstUniqChar(string s) {        
        unordered_map<char, int> umap;
        
        for (int i = 0; i < s.length(); i++) {
            umap[s[i]]++;
        }
        for (int j = 0; j < s.length(); j++) {
            if (umap[s[j]] == 1) return j;
        }
        return -1;
    }
};