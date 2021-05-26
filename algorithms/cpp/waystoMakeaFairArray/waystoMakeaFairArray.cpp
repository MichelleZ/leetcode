// Source: https://leetcode.com/problems/ways-to-make-a-fair-array/
// Author: Miao Zhang
// Date:   2021-05-26

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        vector<int> sums(n + 1);
        for (int i = 1; i < n + 1; i++) {
            sums[i] = sums[i - 1] + (i % 2 ? nums[i - 1] : -nums[i - 1]);
        }
        int res = 0;
        for (int i = 1; i < n + 1; i++) {
            if (sums[i - 1] == sums[n] - sums[i]) {
                res++;
            }
        }
        return res;
    }
};
