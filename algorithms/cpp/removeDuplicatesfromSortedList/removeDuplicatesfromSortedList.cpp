// Source: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// Author: Miao Zhang
// Date:   2021-01-14

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* p1 = head;
        while (p1 && p1->next) {
            if (p1->val == p1->next->val) {
                p1->next = p1->next->next;
            } else {
                p1 = p1->next;
            }
        }
        return head;
    }
};
