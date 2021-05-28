class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int n = strs.size();
        if (n == 0) return res;
        
        int l = strs[0].length();
        
        for (string s : strs) {
            l = l > s.length() ? s.length() : l;
        }
        
        int index = 0;
        for (char c : strs[0]) {
            for (int i = 1; i < n; i++) {
                if (strs[i][index] != c || index > l) return res;
            }
            res += c;
            index++;
        }
        return res;
    }
};