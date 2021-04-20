// Source: https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/
// Author: Miao Zhang
// Date:   2021-04-20

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
class FindElements {
public:
    FindElements(TreeNode* root) {
        recover(root, 0);
    }

    bool find(int target) {
        return s_.count(target);
    }

private:
    unordered_set<int> s_;
    void recover(TreeNode* root, int val) {
        if (!root) return;
        root->val = val;
        s_.insert(val);
        recover(root->left, 2 * val + 1);
        recover(root->right, 2 * val + 2);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
