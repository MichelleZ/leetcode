// Source: https://leetcode.com/problems/sign-of-the-product-of-an-array/
// Author: Miao Zhang
// Date:   2021-06-10

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int res = 1;
        for (int num: nums) {
            if (num == 0) return 0;
            if (num < 0) res = -res;
        }
        return res;
    }
};
