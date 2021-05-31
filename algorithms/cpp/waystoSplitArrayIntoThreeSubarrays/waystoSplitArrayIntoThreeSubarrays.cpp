// Source: https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/
// Author: Miao Zhang
// Date:   2021-05-31

class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int kMod = 1e9 + 7;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }
        int total = nums.back();
        long res = 0;
        // [0, i], [i + 1, j], [j + 1, n - 1]
        for (int i = 0; i < n; i++) {
            auto it1 = lower_bound(begin(nums) + i + 1, end(nums), 2 * nums[i]);
            auto it2 = upper_bound(begin(nums), end(nums) - 1, nums[i] + (total - nums[i]) / 2);
            if (it2 <= it1) continue;
            res += it2 - it1;
        }
        return res % kMod;
    }
};
