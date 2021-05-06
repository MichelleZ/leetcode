// Source: https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/
// Author: Miao Zhang
// Date:   2021-05-05

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minnum = INT_MAX;
        int sums = 0;
        for (int num: nums) {
            sums += num;
            minnum = min(minnum, sums);
        }
        return max(1, 1 - minnum);
    }
};
