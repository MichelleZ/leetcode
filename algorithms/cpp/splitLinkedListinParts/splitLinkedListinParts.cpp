// Source: https://leetcode.com/problems/split-linked-list-in-parts/
// Author: Miao Zhang
// Date:   2021-03-04

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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int cnt = 0;
        ListNode* head = root;
        while (head) {
            cnt++;
            head = head->next;
        }
        int percnt = cnt / k;
        int remain = cnt % k;
        vector<ListNode*> res(k, nullptr);
        ListNode* prev = nullptr;
        head = root;
        for (int i = 0; i < k; i++, remain--) {
            res[i] = head;
            for (int j = 0; j < percnt + (remain > 0); j++) {
                prev = head;
                head = head->next;
            }
            if (prev) prev->next = nullptr;
        }
        return res;
    }
};
