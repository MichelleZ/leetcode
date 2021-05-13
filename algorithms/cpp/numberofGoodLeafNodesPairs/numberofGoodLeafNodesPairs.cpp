// Source: https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/
// Author: Miao Zhang
// Date:   2021-05-13

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
    int countPairs(TreeNode* root, int distance) {
        int res = 0;
        dfs(root, distance, res);
        return res;
    }

private:
    // ret: from root to leaf node distance
    vector<int> dfs(TreeNode* root, int distance, int& res) {
        if (!root) return {};
        if (!root->left && !root->right) return {0};

        vector<int> ret;
        auto left = dfs(root->left, distance, res);
        for (auto& l: left) {
            if (++l > distance) continue;
            ret.push_back(l);
        }
        auto right = dfs(root->right, distance, res);
        for (auto& r: right) {
            if (++r > distance) continue;
            ret.push_back(r);
        }
        for (auto l: left) {
            for (auto r: right) {
                res += (l + r <= distance);
            }
        }
        return ret;
    }
};
