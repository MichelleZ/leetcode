// Source: https://leetcode.com/problems/most-frequent-subtree-sum/
// Author: Miao Zhang
// Date:   2021-02-19

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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> dic;
        vector<int> res;
        int max_freq = -1;
        getSums(root, dic, max_freq, res);
        return res;
    }
    
    int getSums(TreeNode* root, unordered_map<int, int>& dic, int& max_freq, vector<int>& res) {
        if (!root) return 0;
        int val = root->val + getSums(root->left, dic, max_freq, res)
                            + getSums(root->right, dic, max_freq, res);
        int freq = dic[val]++;
        if (freq > max_freq) {
            max_freq = freq;
            res.clear();
        }
        if (freq == max_freq) {
            res.push_back(val);
        }
        return val;
    }
};
