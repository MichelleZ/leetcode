// Source: https://leetcode.com/problems/maximum-erasure-value/
// Author: Miao Zhang
// Date:   2021-05-28

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        int res = 0;
        for (int l = 0, r = 0, sums = 0; r < n; r++) {
            while (s.count(nums[r]) && l < r) {
                sums -= nums[l];
                s.erase(nums[l++]);
            }
            s.insert(nums[r]);
            res = max(res, sums += nums[r]);
        }
        return res;
    }
};
