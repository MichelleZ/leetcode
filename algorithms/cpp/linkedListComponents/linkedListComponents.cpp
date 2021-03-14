// Source: https://leetcode.com/problems/linked-list-components/
// Author: Miao Zhang
// Date:   2021-03-14

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
    int numComponents(ListNode* head, vector<int>& G) {
        int res = 0;
        unordered_set<int> g(G.begin(), G.end());
        while (head) {
            if (g.count(head->val) && (!head->next || !g.count(head->next->val))) {
                res++;
            }
            head = head->next;
        }
        return res;
    }
};
