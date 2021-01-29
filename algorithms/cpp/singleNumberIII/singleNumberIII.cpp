// Source: https://leetcode.com/problems/single-number-iii/
// Author: Miao Zhang
// Date:   2021-01-28

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto &num: nums) res ^= num;
        int mask = 1;
        while ((res & mask) == 0) mask <<= 1;
        int num1 = 0;
        int num2 = 0;
        for (auto &num: nums) {
            if ((num & mask) == 0) num1 ^= num;
            else num2 ^= num;
        }
        return {num1, num2};
    }
};
