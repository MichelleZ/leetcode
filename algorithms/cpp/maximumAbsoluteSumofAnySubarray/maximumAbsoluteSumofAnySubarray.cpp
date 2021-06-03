// Source: https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/
// Author: Miao Zhang
// Date:   2021-06-02

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int posSum = 0, negSum = 0, maxPosSum = 0, minNegSum = 0;
        for (int num: nums) {
            posSum += num;
            maxPosSum = max(maxPosSum, posSum);
            if (posSum < 0) {
                posSum = 0;
            }
            negSum += num;
            minNegSum = min(minNegSum, negSum);
            if (negSum > 0) {
                negSum = 0;
            }
        }
        return max(maxPosSum, -minNegSum);
    }
};
