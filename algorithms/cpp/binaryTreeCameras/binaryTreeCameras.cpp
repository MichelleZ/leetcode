// Source: https://leetcode.com/problems/binary-tree-cameras/
// Author: Miao Zhang
// Date:   2021-03-29

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

enum class State {NONE = 0, COVERED = 1, CAMERA = 2};

class Solution {
public:
    int minCameraCover(TreeNode* root) {
        if (dfs(root) == State::NONE) res_++;
        return res_;
    }

private:
    int res_ = 0;
    State dfs(TreeNode* root) {
        if (!root) return State::COVERED;
        State l = dfs(root->left);
        State r = dfs(root->right);
        if (l == State::NONE || r == State::NONE) {
            res_++;
            return State::CAMERA;
        }
        if (l == State::CAMERA || r == State::CAMERA) {
            return State::COVERED;
        }
        return State::NONE;
    }
};
