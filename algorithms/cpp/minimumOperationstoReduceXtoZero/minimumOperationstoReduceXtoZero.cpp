// Source: https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
// Author: Miao Zhang
// Date:   2021-05-26

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int target = accumulate(begin(nums), end(nums), 0) - x;
        int res = INT_MAX;
        int l = 0;
        int sums = 0;
        for (int r = 0; r < n; r++) {
            sums += nums[r];
            while (sums > target && l <= r) sums -= nums[l++];
            if (sums == target) {
                res = min(res, n - (r - l + 1));
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
