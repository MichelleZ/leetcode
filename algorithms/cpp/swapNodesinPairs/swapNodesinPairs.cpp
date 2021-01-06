// Source: https://leetcode.com/problems/swap-nodes-in-pairs/
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy;
        ListNode *cur, *nxt;
        while (head and head->next) {
            cur = head;
            nxt = head->next;
            
            pre->next = nxt;
            cur->next = nxt->next;
            nxt->next = cur;
            
            pre = cur;
            head = cur->next;
        }
        return dummy->next;
    }
};
