// Source: https://leetcode.com/problems/frequency-of-the-most-frequent-element/
// Author: Miao Zhang
// Date:   2021-06-11

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int l = 0;
        long sums = 0;
        int res = 0;
        for (int r = 0; r < nums.size(); r++) {
            sums += nums[r];
            while (l < r && sums + k < static_cast<long>(nums[r]) * (r - l + 1))
                sums -= nums[l++];
            res = max(res, r - l + 1);
        }
        return res;
    }
};
