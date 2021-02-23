// Source: https://leetcode.com/problems/subtree-of-another-tree/
// Author: Miao Zhang
// Date:   2021-02-23

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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t == nullptr) return true;
        if (s == nullptr or t == nullptr) return false;
        return isSametree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }

    bool isSametree(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t == nullptr) return true;
        if (s == nullptr || t == nullptr) return false;
        return (s->val == t->val
                && isSametree(s->left, t->left)
                && isSametree(s->right, t->right));
    }
};
