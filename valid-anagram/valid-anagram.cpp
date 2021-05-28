class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int n = s.length();
        vector<int> countS(26);
        vector<int> countT(26);
        for (int i = 0; i < n; i++) {
            int indexS = s[i] - 'a';
            int indexT = t[i] - 'a';
            countS[indexS]++;
            countT[indexT]++;
        }
        return (countS == countT);
    }
};