// Source: https://leetcode.com/problems/partition-list/
// Author: Miao Zhang
// Date:   2021-01-15

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* large = new ListNode(0);
        ListNode* ps = small, *pl = large;
        while (head) {
            if (head->val < x) {
                ps->next = head;
                ps = ps->next;
            } else {
                pl->next = head;
                pl = pl->next;
            }
            ListNode* tmp = head->next;
            head->next = nullptr;
            head = tmp;
        }
        ps->next = large->next;
        return small->next;
    }
};
