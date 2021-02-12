// Source: https://leetcode.com/problems/add-two-numbers-ii/
// Author: Miao Zhang
// Date:   2021-02-12

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1;
        stack<int> st2;
        while (l1) {
            st1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            st2.push(l2->val);
            l2 = l2->next;
        }
        ListNode* head = nullptr;
        int carry = 0;
        while (!st1.empty() || !st2.empty() || carry) {
            carry += st1.empty() ? 0 : st1.top();
            carry += st2.empty() ? 0 : st2.top();
            if (!st1.empty()) st1.pop();
            if (!st2.empty()) st2.pop();
            ListNode* node = new ListNode(carry % 10);
            carry /= 10;
            node->next = head;
            head = node;
        }
        return head;
    }
};
