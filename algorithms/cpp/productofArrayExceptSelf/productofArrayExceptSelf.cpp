// Source: https://leetcode.com/problems/product-of-array-except-self/
// Author: Miao Zhang
// Date:   2021-01-28

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        res[0] = 1;
        int tmp = 1;
        for (int i = 1; i < nums.size(); i++) {
            tmp *= nums[i - 1];
            res[i] = tmp;
        }
        tmp = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            tmp *= nums[i + 1];
            res[i] *= tmp;
        }
        return res;
    }
};
