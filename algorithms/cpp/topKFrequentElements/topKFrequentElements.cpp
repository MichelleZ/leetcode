// Source: https://leetcode.com/problems/top-k-frequent-elements/
// Author: Miao Zhang
// Date:   2021-02-03

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (auto &n: nums) {
            count[n]++;
        }
        priority_queue<pair<int, int>> heap;
        for (auto &p: count) {
            heap.emplace(-p.second, p.first);
            if (heap.size() > k) heap.pop();
        }
        vector<int> res;
        int n = heap.size();
        for (int i = 0; i < n; i++) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};
