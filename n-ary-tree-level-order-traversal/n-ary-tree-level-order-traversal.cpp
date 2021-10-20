/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (!root) return result;
        vector<int> r{root->val};
        result.push_back(r);
        queue<Node*> q;
        if (!root->children.empty()) {
            for (auto& c : root->children) {
                q.push(c);
            }
        }
        while (!q.empty()) {
            vector<int> temp;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                if (!node->children.empty()) {
                    for (auto &c : node->children) q.push(c);
                }
                temp.push_back(node->val);
            }
            if (!temp.empty()) result.push_back(temp);
        }
        return result;
    }
};