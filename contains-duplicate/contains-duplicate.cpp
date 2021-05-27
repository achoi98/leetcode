class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        /* naive
        
        vector<int> history;
        for (int i = 0; i < nums.size(); i++) {
            if (find(history.begin(), history.end(), nums[i]) == history.end()) {
                history.push_back(nums[i]);
            }
            else return true;
        }
        return false;
        */
        int n = nums.size();
        set<int> s;
        for (int i = 0; i < n; i++) {
            s.insert(nums[i]);
        }
        return (s.size() != n);
    }
};