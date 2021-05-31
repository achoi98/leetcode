class Solution {
public:
    
    int rob(vector<int>& nums) {
        vector<int> cache(nums.size(), -1);
        return robFrom(0, nums, cache);
    }
    
    int robFrom(int index, vector<int>& nums, vector<int>& cache) {
        if (index >= nums.size()) return 0;
        if (cache[index] > -1) return cache[index];
        
        int ans = max(robFrom(index + 1, nums, cache), robFrom(index + 2, nums, cache) + nums[index]);
        cache[index] = ans;
        return ans;
    }
};