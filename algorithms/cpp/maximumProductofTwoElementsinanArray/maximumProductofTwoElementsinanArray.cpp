// Source: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
// Author: Miao Zhang
// Date:   2021-05-09

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first = 0;
        int second = 0;
        for (int n: nums) {
            if (n > first) {
                second = first;
                first = n;
            } else if (n > second) {
                second = n;
            }
        }
        return (first - 1) * (second - 1);
    }
};
