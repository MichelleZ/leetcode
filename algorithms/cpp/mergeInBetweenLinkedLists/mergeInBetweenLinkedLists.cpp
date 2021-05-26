// Source: https://leetcode.com/problems/merge-in-between-linked-lists/
// Author: Miao Zhang
// Date:   2021-05-26

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode dummy(0, list1);
        ListNode* prev_a = &dummy;
        for (int i = 0; i < a; i++)
            prev_a = prev_a->next;
        ListNode* nodeb = prev_a->next;
        for (int i = a; i <= b; i++)
            nodeb = nodeb->next;
        ListNode* tail2 = list2;
        while (tail2->next)
            tail2 = tail2->next;
        prev_a->next = list2;
        tail2->next = nodeb;
        return list1;
    }
};
