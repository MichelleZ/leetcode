// Source: https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/
// Author: Miao Zhang
// Date:   2021-04-05

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
    TreeNode* recoverFromPreorder(string S) {
        int i = 0;
        return recover(S, i, 0);
    }

private:
    TreeNode* recover(const string& s, int& i, int depth) {
        int d = getD(s, i);
        if (d != depth) {
            i -= d;
            return nullptr;
        }
        auto root = new TreeNode(getVal(s, i));
        root->left = recover(s, i, d + 1);
        root->right = recover(s, i, d + 1);
        return root;
    }

    int getD(const string&s, int& i) {
        int d = 0;
        while (i < s.length() && s[i] == '-') {
            d++;
            i++;
        }
        return d;
    }

    int getVal(const string&s, int& i) {
        int val = 0;
        while (i < s.length() && isdigit(s[i])) {
            val = val * 10 + (s[i++] - '0');
        }
        return val;
    }
};
