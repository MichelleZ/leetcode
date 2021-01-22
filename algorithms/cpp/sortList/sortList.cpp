// Source: https://leetcode.com/problems/sort-list/
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* mid = getMid(head);
        ListNode* l = head;
        ListNode* r = mid->next;
        mid->next = nullptr;
        return merge(sortList(l), sortList(r));
    }
    
    ListNode* getMid(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    ListNode* merge(ListNode* p, ListNode* q) {
        ListNode* dummy = new ListNode(0);
        ListNode* tmp = dummy;
        while (p && q) {
            if (p->val <= q->val) {
                tmp->next = p;
                p = p->next;
            } else {
                tmp->next = q;
                q = q->next;
            }
            tmp = tmp->next;
        }
        if (p) tmp->next = p;
        if (q) tmp->next = q;
        return dummy->next;
    }
};
