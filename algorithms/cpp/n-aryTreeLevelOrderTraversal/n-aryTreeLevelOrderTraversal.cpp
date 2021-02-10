// Source: https://leetcode.com/problems/n-ary-tree-level-order-traversal/
// Author: Miao Zhang
// Date:   2021-02-10

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
        if (!root) return {};
        vector<vector<int>> res;
        deque<Node*> q;
        q.push_back(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> tmp;
            for (int i = 0; i < n; i++) {
                Node* node = q.front();
                q.pop_front();
                tmp.push_back(node->val);
                for (auto ch: node->children) {
                    q.push_back(ch);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};
