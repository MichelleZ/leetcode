// Source: https://leetcode.com/problems/next-greater-node-in-linked-list/
// Author: Miao Zhang
// Date:   2021-04-02

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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums;
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
        stack<int> st;
        vector<int> res(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i]) st.pop();
            res[i] = st.empty() ? 0 : st.top();
            st.push(nums[i]);
        }
        return res;
    }
};
