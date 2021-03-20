// Source: https://leetcode.com/problems/leaf-similar-trees/
// Author: Miao Zhang
// Date:   2021-03-20

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafs1;
        vector<int> leafs2;
        getLeafs(root1, leafs1);
        getLeafs(root2, leafs2);
        return leafs1 == leafs2;
    }

private:
    void getLeafs(TreeNode* root, vector<int>& leafs) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) {
            leafs.push_back(root->val);
        }
        getLeafs(root->left, leafs);
        getLeafs(root->right, leafs);
    }
};
