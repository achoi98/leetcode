class Solution {
public:
    int dp(int i, int left, int m, int n, vector<int>& nums, vector<int>& multipliers, vector<vector<int>>& memo) {
        if (i == m) return 0;
        
        int mult = multipliers[i];
        int right = n - 1 - (i - left);
        
        if (memo[i][left] == 0) {
            memo[i][left] = max(mult * nums[left] + dp(i + 1, left + 1, m, n, nums, multipliers, memo), mult * nums[right] + dp(i + 1, left, m, n, nums, multipliers, memo));
        }
        
        return memo[i][left];
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size();
        int n = nums.size();
        vector<vector<int>> memo(m, vector<int> (m, 0));
        
        
        return dp(0, 0, m, n, nums, multipliers, memo);
    }
};