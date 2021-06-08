// Source: https://leetcode.com/problems/maximum-score-of-a-good-subarray/
// Author: Miao Zhang
// Date:   2021-06-08

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        for (int i = k, j = k, m = nums[k];;) {
            res = max(res, m * (j - i + 1));
            if (j - i + 1 == n) break;
            int l = i ? nums[i - 1] : -1;
            int r = j < n - 1 ? nums[j + 1] : -1;
            if (l >= r) {
                m = min(m, nums[--i]);
            } else {
                m = min(m, nums[++j]);
            }
        }
        return res;
    }
};
