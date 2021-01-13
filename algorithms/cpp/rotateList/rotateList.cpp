// Source: https://leetcode.com/problems/rotate-list/
// Author: Miao Zhang
// Date:   2021-01-13

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return nullptr;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int count = 0;
        ListNode* pi = dummy;
        while (pi->next) {
            count++;
            pi = pi->next;
        }
        k = k % count;
        // rotate k times original list
        if (k == 0 || count == 1) return head;
    
        pi->next = head;
        pi = dummy;
        for (int i = 0; i < count - k; i++) {
            pi = pi->next;
        }
        ListNode* pj = pi->next;
        pi->next = nullptr;
        return pj;
    }
};
