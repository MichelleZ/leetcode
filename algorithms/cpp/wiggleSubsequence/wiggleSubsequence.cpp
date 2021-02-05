// Source: https://leetcode.com/problems/wiggle-subsequence/
// Author: Miao Zhang
// Date:   2021-02-05

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return 1;
        int inc = 1;
        int dec = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) inc = dec + 1;
            else if (nums[i] < nums[i - 1]) dec = inc + 1;
        }
        return max(inc, dec);
    }
};
