// Source: https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
// Author: Miao Zhang
// Date:   2021-05-27

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> increase(n, 1);
        vector<int> decrease(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    increase[i] = max(increase[i], increase[j] + 1);
                }
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (nums[i] > nums[j]) {
                    decrease[i] = max(decrease[i], decrease[j] + 1);
                }
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (increase[i] < 2 || decrease[i] < 2) continue;
            res = min(res, n - (increase[i] + decrease[i] - 1));
        }
        return res;
    }
};
