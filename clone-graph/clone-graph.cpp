/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return node;
        unordered_map<int, Node*> map;
        queue<Node*> q;
        q.push(node);
        Node* clone = new Node(node->val);
        map[node->val] = clone;
        while (!q.empty()) {
            Node* pop = q.front();
            for (Node* n : pop->neighbors) {
                if (!map.count(n->val)) {
                    Node* c = new Node(n->val);
                    map[n->val] = c;
                    q.push(n);
                }
                map[pop->val]->neighbors.push_back(map[n->val]);
            }
            q.pop();
        }
        return map[node->val];
    }
};