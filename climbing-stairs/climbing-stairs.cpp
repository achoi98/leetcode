class Solution {
public:
    int climbStairs(int n) {
        vector<int> steps(n + 1);
        if (n == 1) return 1;
        if (n == 2) return 2;
        steps[1] = 1;
        steps[2] = 2;
        return helper(n, steps);
    }
    
    int helper(int n, vector<int>& steps) {
        if (steps[n] != 0) return steps[n];
        steps[n] = helper(n - 1, steps) + helper(n - 2, steps);
        return steps[n];
    }
};