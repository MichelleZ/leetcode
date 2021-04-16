// Source: https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
// Author: Miao Zhang
// Date:   2021-04-15

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> sums;
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
        dummy->next = head;
        sums[0] = p;
        p = p->next;
        int s = 0, tmps = 0;
        while (p) {
            s += p->val;
            if (sums.find(s) != sums.end()) {
                ListNode* tmp = sums[s]->next;
                sums[s]->next = p->next;
                tmps = s;
                while (tmp != nullptr && tmp != p) {
                    tmps += tmp->val;
                    sums.erase(tmps);
                    tmp = tmp->next;
                }
            } else {
                sums[s] = p;
            }
            p = p->next;
        }
        return dummy->next;
    }
};
