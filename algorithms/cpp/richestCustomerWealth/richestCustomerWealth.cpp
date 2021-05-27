// Source: https://leetcode.com/problems/richest-customer-wealth/
// Author: Miao Zhang
// Date:   2021-05-27

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res = 0;
        for (auto& row: accounts) {
            res = max(res, accumulate(begin(row), end(row), 0));
        }
        return res;
    }
};
