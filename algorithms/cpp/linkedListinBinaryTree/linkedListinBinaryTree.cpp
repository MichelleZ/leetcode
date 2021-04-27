// Source: https://leetcode.com/problems/linked-list-in-binary-tree/
// Author: Miao Zhang
// Date:   2021-04-27

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;
        return isPath(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }

private:
    bool isPath(ListNode* head, TreeNode* root) {
        if (!head) return true;
        if (!root) return false;
        if (root->val != head->val) return false;
        return isPath(head->next, root->left) || isPath(head->next, root->right);
    }
};
