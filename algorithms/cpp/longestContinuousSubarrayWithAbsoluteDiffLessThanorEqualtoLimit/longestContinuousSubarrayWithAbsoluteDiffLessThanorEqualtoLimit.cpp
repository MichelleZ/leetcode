// Source: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
// Author: Miao Zhang
// Date:   2021-05-07

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> s;
        int l = 0;
        int res = 0;
        for (int r = 0; r < nums.size(); r++) {
            s.insert(nums[r]);
            while (*rbegin(s) - *begin(s) > limit) {
                s.erase(s.equal_range(nums[l++]).first);
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
