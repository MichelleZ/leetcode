// Source: https://leetcode.com/problems/single-number-ii/
// Author: Miao Zhang
// Date:   2021-01-21

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int count = 0;
            for (auto num: nums) {
                count += (num >> i) & 1;
            }
            res |= (count % 3) << i;
        }
        return res;
    }
};
