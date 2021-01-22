// Source: https://leetcode.com/problems/insertion-sort-list/
// Author: Miao Zhang
// Date:   2021-01-22

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
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return nullptr;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        while (head->next) {
            if (head->val <= head->next->val) {
                head = head->next;
            } else {
                ListNode* nxt = head->next;
                head->next = nxt->next;
                ListNode* p = dummy;
                while (p->next->val <= nxt->val) {
                    p = p->next;
                }
                nxt->next = p->next;
                p->next = nxt;
            }
        }
        return dummy->next;
    }
};
