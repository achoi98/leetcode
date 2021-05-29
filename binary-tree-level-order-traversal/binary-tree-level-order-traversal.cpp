/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        int depth = maxDepth(root);
        vector<vector<int>> res(depth);
        helper(root, 0, res);
        
        return res;
    }
    
    void helper(TreeNode* root, int level, vector<vector<int>>& v) {
        if (root != nullptr) {
            v[level].push_back(root->val);
            helper(root->left, level + 1, v);
            helper(root->right, level + 1, v);
        }
    }
    
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};