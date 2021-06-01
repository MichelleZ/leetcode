// Source: https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/
// Author: Miao Zhang
// Date:   2021-06-01

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int res = 0;
        int cur = 0;
        for (auto& r: rectangles) {
            if (min(r[0], r[1]) > cur) {
                cur = min(r[1], r[0]);
                res = 0;
            }
            if (min(r[0], r[1]) == cur) res++;
        }
        return res;
    }
};
