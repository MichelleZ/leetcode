// Source: https://leetcode.com/problems/all-possible-full-binary-trees/
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
    vector<TreeNode*> allPossibleFBT(int n) {
        return trees(n);
    }

private:
    unordered_map<int, vector<TreeNode*>> memo;

    vector<TreeNode*> trees(int n) {
        if (memo.count(n)) return memo[n];
        vector<TreeNode*> res = vector<TreeNode*>();
        if (n == 1) res.push_back(new TreeNode(0));
        if (n % 2 == 0) return {};
        for (int i = 1; i < n; i+= 2) {
            for (const auto& l: trees(i)) {
                for (const auto& r: trees(n - i - 1)) {
                    auto root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
