// Source: https://leetcode.com/problems/smallest-range-i/
// Author: Miao Zhang
// Date:   2021-03-23

class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        auto it = std::minmax_element(A.begin(), A.end());
        int maxval = *it.second;
        int minval = *it.first;
        return max(0, maxval - minval - 2 * K);
    }
};
