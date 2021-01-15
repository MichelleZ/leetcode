// Source: https://leetcode.com/problems/reverse-linked-list-ii/
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p = dummy;
        
        for (int i = 0; i < m - 1; i++) {
            p = p->next;
        }
        
        ListNode* pre = nullptr;
        ListNode* cur = p->next;
        for(int i = 0; i < n - m + 1; i++) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        
        p->next->next = cur;
        p->next = pre;
        
        return dummy->next;
    }
};
