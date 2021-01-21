// Source: https://leetcode.com/problems/single-number/
// Author: Miao Zhang
// Date:   2021-01-21

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto num: nums) {
            res ^= num;
        }
        return res;
    }
};
