// Source: https://leetcode.com/problems/complete-binary-tree-inserter/
// Author: Miao Zhang
// Date:   2021-03-24

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
class CBTInserter {
public:
    CBTInserter(TreeNode* root) : root_(root), q_({root}) {
        
    }
    
    int insert(int v) {
        while (!q_.empty()) {
            TreeNode* node = q_.front();
            if (node->left && node->right) {
                q_.push_back(node->left);
                q_.push_back(node->right);
                q_.pop_front();
            } else if (node->left) {
                node->right = new TreeNode(v);
                return node->val;
            } else {
                node->left = new TreeNode(v);
                return node->val;
            }
        }
        return -1;
    }
    
    TreeNode* get_root() {
        return root_;
    }

private:
    deque<TreeNode*> q_;
    TreeNode* root_;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
