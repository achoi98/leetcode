class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        using namespace std;
        unordered_map<int,int> umap;        // key=number,value=index
        vector<int> result;
        
        for (int i=0; i<nums.size(); i++)
        {
            int toFind = target - nums[i];
            if (umap.find(toFind)!=umap.end())
            {
                result.push_back(umap[toFind]);
                result.push_back(i);
                return result;
            }
            // number not found
            umap[nums[i]] = i;
        }
        return result;
    }
};