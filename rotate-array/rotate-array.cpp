class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       /* 
        // method 1
        vector<int> new_nums(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            new_nums[(i + k) % nums.size()] = nums[i];
        }
        nums = new_nums;
        */
        
        // method 2
        k = k % nums.size();
        int count = 0;
        for (int i = 0; count < nums.size(); i++) {
            int curr = i;
            int prev = nums[i];
            do {
                int next = (curr + k) % nums.size();
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                curr = next;
                count++;
            } while (i != curr);
        }
    }
};