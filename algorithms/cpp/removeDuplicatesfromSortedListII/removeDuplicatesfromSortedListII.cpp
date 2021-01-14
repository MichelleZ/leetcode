// Source: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
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
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p1 = dummy;
        while (p1->next && p1->next->next) {
            if (p1->next->val == p1->next->next->val) {
                ListNode* p2 = p1->next->next;
                while (p2->next && p2->next->val == p1->next->val) p2 = p2->next;
                p1->next = p2->next;
                if (p1->next == nullptr) break;
            } else {
                p1 = p1->next;
            }
        }
        return dummy->next;
    }
};
