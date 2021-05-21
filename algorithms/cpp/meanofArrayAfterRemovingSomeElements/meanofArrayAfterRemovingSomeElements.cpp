// Source: https://leetcode.com/problems/mean-of-array-after-removing-some-elements/
// Author: Miao Zhang
// Date:   2021-05-21

class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(begin(arr), end(arr));
        int offset = arr.size() / 20;
        int sums = accumulate(begin(arr) + offset, end(arr) - offset, 0);
        return static_cast<double>(sums) / (arr.size() - 2 * offset);
    }
};
