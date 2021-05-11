// Source: https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/
// Author: Miao Zhang
// Date:   2021-05-10

class Solution {
public:
    double average(vector<int>& salary) {
        auto [low, high] = minmax_element(begin(salary), end(salary));
        int sums = accumulate(begin(salary), end(salary), 0);
        return (sums - *low - *high) * 1.0 / (salary.size() - 2);
    }
};
