class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0, pos = 0, max = 0;
        unordered_set<char> chars;
        for (char c : s) {
            if (chars.count(c)) {
                while (s[pos] != c) {
                    chars.erase(s[pos]);
                    length--;
                    pos++;
                }
                chars.erase(s[pos]);
                length--;
                pos++;
            }
            chars.insert(c);
            length++;
            if (length > max) max = length;
        }
        return max;
    }
};