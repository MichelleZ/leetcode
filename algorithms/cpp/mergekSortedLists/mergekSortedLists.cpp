// Source: https://leetcode.com/problems/merge-k-sorted-lists/
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

struct cmp {
    bool operator () (ListNode *a, ListNode *b) {
        return a->val > b->val; // mini the first
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *dummy = new ListNode();
        ListNode *head = dummy;
        ListNode *node = NULL;
        priority_queue<ListNode*, vector<ListNode*>, cmp> heap;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                heap.push(lists[i]);
            }
        }
        while (!heap.empty()) {
            node = heap.top();
            heap.pop();
            head->next = node;
            head = head->next;
            if (node->next) {
                heap.push(node->next);
            }    
        }
        return dummy->next;
    }
    
};
