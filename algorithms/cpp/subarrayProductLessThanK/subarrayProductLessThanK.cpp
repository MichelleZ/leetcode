// Source: https://leetcode.com/problems/subarray-product-less-than-k/
// Author: Miao Zhang
// Date:   2021-03-03

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int res = 0, prod = 1, left = 0;
        for (int right = 0; right < nums.size(); right++) {
            prod *= nums[right];
            while (left <= right && prod >= k) prod /= nums[left++];
            res += right - left + 1;
        }
        return res;
    }
};
