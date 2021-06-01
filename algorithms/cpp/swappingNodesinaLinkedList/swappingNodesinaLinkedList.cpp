// Source: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
// Author: Miao Zhang
// Date:   2021-06-01

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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int l = 0;
        ListNode* p = head;
        while(p) {
            p = p->next;
            l++;
        }
        p = head;
        ListNode* n1 = nullptr;
        ListNode* n2 = nullptr;
        for (int i = 1; i <= l; i++, p = p->next) {
            if (i == k) n1 = p;
            if (i == l - k + 1) n2 = p;
        }
        swap(n1->val, n2->val);
        return head;
    }
};
