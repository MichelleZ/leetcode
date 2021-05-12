// Source: https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/
// Author: Miao Zhang
// Date:   2021-05-12

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) return 0;
        sort(begin(nums), end(nums));
        int res = INT_MAX;
        for (int i = 0; i < 4; i++) {
            res = min(res, nums[n - 4 + i] - nums[i]);
        }
        return res;
    }
};
