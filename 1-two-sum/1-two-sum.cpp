class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (umap.count(target - nums[i]) > 0) {
                res.push_back(umap[target - nums[i]]);
                res.push_back(i);
                return res;
            }
            umap.emplace(nums[i], i);
        }
        return res;
    }
};