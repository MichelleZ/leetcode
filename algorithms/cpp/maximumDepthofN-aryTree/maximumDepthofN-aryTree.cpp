// Source: https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
// Author: Miao Zhang
// Date:   2021-02-22

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
    int maxDepth(Node* root) {
        if (!root) return 0;
        int res = 0;
        for (auto ch: root->children) {
            res = max(res, maxDepth(ch));
        }
        return 1 + res;
    }
};
