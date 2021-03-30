// Source: https://leetcode.com/problems/squares-of-a-sorted-array/
// Author: Miao Zhang
// Date:   2021-03-30

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());
        auto e = prev(end(nums));
        auto s = begin(nums);
        auto it = end(res);
        while (--it >= res.begin()) {
            if (e > s && abs(*e) > abs(*s)) {
                *it = pow(*e--, 2);
            } else {
                *it = pow(*s++, 2);
            }
        }
        return res;
    }
};
