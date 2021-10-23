class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end());          // reverse entire array
        reverse(nums.begin(), nums.begin() + k);    // reverse first k elements
        reverse(nums.begin() + k, nums.end());      // reverse last n-k elements
    }
};