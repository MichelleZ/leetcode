// Source: https://leetcode.com/problems/find-mode-in-binary-search-tree/
// Author: Miao Zhang
// Date:   2021-02-17

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
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return res;
    }

private:
    int val_ = 0;
    int count_ = 0;
    int max_count_ = 0;
    vector<int> res;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        visit(root->val);
        inorder(root->right);
    }

    void visit(int val) {
        if (count_ > 0 && val == val_) {
            count_++;
        } else {
            val_ = val;
            count_ = 1;
        }
        if (count_ > max_count_) {
            max_count_ = count_;
            res.clear();
        }
        if (count_ == max_count_) {
            res.push_back(val);
        }
    }

};
