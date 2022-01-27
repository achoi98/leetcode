class Solution {
public:
    int m, n;
    int memo[1000][1000]; // m <= 1000
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        n = nums.size();
        m = multipliers.size();
        memset(memo, -1, sizeof(memo));
        return dp(0, 0, nums, multipliers);
    }
    
    int dp(int i, int left, vector<int>& nums, vector<int>& multipliers) {
        if (i == m) return 0;
        if (memo[i][left] != -1) return memo[i][left];
        memo[i][left] = max(nums[left] * multipliers[i] + dp(i + 1, left + 1, nums, multipliers), nums[n - 1 - (i - left)] * multipliers[i] + dp(i + 1, left, nums, multipliers));
        return memo[i][left];
    }
};