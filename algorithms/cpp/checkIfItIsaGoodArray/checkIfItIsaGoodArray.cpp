// Source: https://leetcode.com/problems/check-if-it-is-a-good-array/
// Author: Miao Zhang
// Date:   2021-04-19

class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g = nums[0];
        for (int n: nums) {
            g = gcd(g, n);
        }
        return g == 1;
    }
};
