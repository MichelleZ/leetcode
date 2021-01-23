// Source: https://leetcode.com/problems/maximum-product-subarray/
// Author: Miao Zhang
// Date:   2021-01-22

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minval = nums[0];
        int maxval = nums[0];
        int globalmax = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int lastmax = maxval;
            maxval = max(maxval * nums[i], max(minval * nums[i], nums[i]));
            minval = min(minval * nums[i], min(lastmax * nums[i], nums[i]));
            globalmax = max(globalmax, maxval);
        }
        return globalmax;
    }
};
