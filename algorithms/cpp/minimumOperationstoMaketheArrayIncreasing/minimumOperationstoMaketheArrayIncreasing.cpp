// Source: https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/
// Author: Miao Zhang
// Date:   2021-06-10

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        int last = 0;
        for (int num: nums) {
            if (num <= last) {
                res += ++last - num;
            } else {
                last = num;
            }
        }
        return res;
    }
};
