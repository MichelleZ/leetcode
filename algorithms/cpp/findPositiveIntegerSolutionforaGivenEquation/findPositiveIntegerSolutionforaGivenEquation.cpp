// Source: https://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation/
// Author: Miao Zhang
// Date:   2021-04-19

/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> res;
        for (int x = 1; x < 1001; x++) {
            if (customfunction.f(x, 1) > z) break;
            int l = 1;
            int r = 1001;
            while (l < r) {
                int m = l + (r - l) / 2;
                int t = customfunction.f(x, m);
                if (t > z) {
                    r = m;
                } else if (t < z) {
                    l = m + 1;
                } else {
                    res.push_back({x, m});
                    break;
                }

            }
        }
        return res;
    }
};
