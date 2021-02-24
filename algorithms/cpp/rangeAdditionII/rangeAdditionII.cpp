// Source: https://leetcode.com/problems/range-addition-ii/
// Author: Miao Zhang
// Date:   2021-02-24

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for (const auto& p: ops) {
            m = min(m, p[0]);
            n = min(n, p[1]);
        }
        return m * n;
    }
};
