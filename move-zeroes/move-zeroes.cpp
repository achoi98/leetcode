class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int index;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                index = i + 1;
                while (index < n && nums[index] == 0) {
                    index++;
                }
                if (index >= n) return;
                nums[i] = nums[index];
                nums[index] = 0;
                }
            }
    }
};