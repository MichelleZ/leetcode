// Source: https://leetcode.com/problems/n-ary-tree-postorder-traversal/
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
    vector<int> postorder(Node* root) {
        vector<int> res;
        pre(root, res);
        return res;
    }

    void pre(Node* root, vector<int>& res) {
        if (!root) return;
        for (auto ch: root->children) pre(ch, res);
        res.push_back(root->val);
    }
};

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if (!root) return res;
        stack<Node*> st;
        st.push(root);
        while (!st.empty()) {
            Node* node = st.top();
            res.push_back(node->val);
            st.pop();
            for (auto ch: node->children) {
                st.push(ch);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
