class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        vector<char> chars(s.length());
        for (int i = 0; i < s.length(); i++) {
            chars[indices[i]] = s.at(i);
        }
        string ss(chars.begin(), chars.end());
        return ss;
    }
};