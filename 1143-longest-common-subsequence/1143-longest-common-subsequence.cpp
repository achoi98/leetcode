class Solution {
public:
    int rows, cols;
    int dp(string& text1, string& text2, int p1, int p2, vector<vector<int>>& memo) {
        if (p1 >= rows || p2 >= cols) return 0;
        if (memo[p1][p2] != -1) return memo[p1][p2];
        
        int n = 0;
        if (text1[p1] == text2[p2]) {
            n = 1 + dp(text1, text2, p1 + 1, p2 + 1, memo);
        }
        else {
            n = max(dp(text1, text2, p1, p2 + 1, memo), dp(text1, text2, p1 + 1, p2, memo));
        }
        
        memo[p1][p2] = n;
        return memo[p1][p2];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int length1 = text1.size();
        int length2 = text2.size();
        rows = length1;
        cols = length2;
        vector<vector<int>> memo(length1, vector<int>(length2, -1));
        
        return dp(text1, text2, 0, 0, memo);
    }
};