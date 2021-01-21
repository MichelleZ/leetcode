// Source: https://leetcode.com/problems/reorder-list/
// Author: Miao Zhang
// Date:   2021-01-21

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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return;
        }
        
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* head2 = slow->next;
        slow->next = nullptr;
        
        ListNode* pre = nullptr;
        ListNode* cur = head2;
        while (cur) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        
        ListNode* p1 = head;
        ListNode* p2 = pre;
        while (p2) {
            ListNode* tmp1 = p1->next;
            ListNode* tmp2 = p2->next;
            p1->next = p2;
            p2->next = tmp1;
            p1 = tmp1;
            p2 = tmp2;
        }
    }
};
