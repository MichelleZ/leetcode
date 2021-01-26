// Source: https://leetcode.com/problems/kth-largest-element-in-an-array/
// Author: Miao Zhang
// Date:   2021-01-26

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, less<int>> heap;
        for (auto &num: nums) {
            heap.push(num);
        }
        int res;
        for (int i = 0; i < k; i++) {
            res = heap.top();
            heap.pop();
        }
        return res;
    }
};
