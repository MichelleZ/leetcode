// Source: https://leetcode.com/problems/n-ary-tree-preorder-traversal/
// Author: Miao Zhang
// Date:   2021-02-23

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
    vector<int> preorder(Node* root) {
        vector<int> res;
        pre(root, res);
        return res;
    }
    
    void pre(Node* root, vector<int>& res) {
        if (!root) return;
        res.push_back(root->val);
        for (auto ch: root->children) pre(ch, res);
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if (!root) return res;
        stack<Node*> st;
        st.push(root);
        while (!st.empty()) {
            Node* node = st.top();
            st.pop();
            res.push_back(node->val);
            for (auto it = node->children.rbegin(); it != node->children.rend(); it++) {
                st.push(*it);
            }
        }
        return res;
    }
};
