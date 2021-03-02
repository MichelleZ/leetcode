// Source: https://leetcode.com/problems/degree-of-an-array/
// Author: Miao Zhang
// Date:   2021-03-02

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> indices;
        for (int i = 0; i < nums.size(); i++) {
            indices[nums[i]].push_back(i);
        }
        size_t degree = 0;
        for (const auto& kv: indices) {
            degree = max(degree, kv.second.size());
        }
        int res = nums.size();
        for (const auto& kv: indices) {
            if (kv.second.size() != degree) continue;
            res = min(res, kv.second.back() - kv.second.front() + 1);
        }
        return res;
    }
};
