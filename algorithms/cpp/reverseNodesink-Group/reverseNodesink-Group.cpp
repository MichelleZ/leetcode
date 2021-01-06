// Source: https://leetcode.com/problems/reverse-nodes-in-k-group/
// Author: Miao Zhang
// Date:   2021-01-06

/*************************************************
 * pre ----k elements---- last to be reversed
 * pre 0, 1, 2, 3...k-1   last
*************************************************/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) return NULL;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        while (pre != NULL) {
            pre = reverse(pre, k);
        }
        return dummy->next;
    }
    
    ListNode* reverse(ListNode* pre, int k) {
        ListNode* last = pre;
        for (int i = 0; i < k + 1; i++) {
            last = last->next;
            if (i != k && last == NULL) return NULL;
        }
        ListNode *tail = pre->next;
        ListNode *cur = pre->next->next;
        while (cur != last) {
            ListNode *nxt = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            tail->next = nxt;
            cur = nxt;
        }
        return tail;
    }
};
