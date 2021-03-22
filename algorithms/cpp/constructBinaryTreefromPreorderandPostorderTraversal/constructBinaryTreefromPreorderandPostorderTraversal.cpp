// Source: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
// Author: Miao Zhang
// Date:   2021-03-22

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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return dfs(pre, 0, pre.size() - 1, post, 0, post.size() - 1);
    }

private:
    TreeNode* dfs(vector<int>& pre, int pre_start, int pre_end, vector<int>& post,
                  int post_start, int post_end) {
        if (pre_start > pre_end || post_start > post_end) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(pre[pre_start]);
        if (pre_start == pre_end) return root;
        int idx = post_start;
        while (post[idx] != pre[pre_start + 1]) idx++;
        root->left = dfs(pre, pre_start + 1, pre_start + 1 + (idx - post_start),
                         post, post_start, idx);
        root->right = dfs(pre, pre_end - (post_end - 1 - idx - 1), pre_end,
                          post, idx + 1, post_end - 1);
        return root;
    }
};
