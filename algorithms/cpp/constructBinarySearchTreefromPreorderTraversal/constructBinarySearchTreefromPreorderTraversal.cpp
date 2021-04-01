// Source: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
// Author: Miao Zhang
// Date:   2021-04-01

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, 0, preorder.size());
    }

private:
    TreeNode* build(vector<int>& preorder, int s, int e) {
        if (s >= e) return nullptr;
        auto root = new TreeNode(preorder[s]);
        int i = s;
        while (i < e && preorder[i] <= preorder[s]) i++;
        root->left = build(preorder, s + 1, i);
        root->right = build(preorder, i, e);
        return root;
    }
};
