// Source: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Author: Miao Zhang
// Date:   2021-01-06

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || n < 0) {
            return NULL;
        }
        
        ListNode *slow, *fast;
        slow = fast = head;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        if (fast == NULL) return head->next;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};
