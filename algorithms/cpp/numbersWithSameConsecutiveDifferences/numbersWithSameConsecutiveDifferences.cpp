// Source: https://leetcode.com/problems/numbers-with-same-consecutive-differences/
// Author: Miao Zhang
// Date:   2021-03-29

class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        if (n == 1) res.push_back(0);
        for (int i = 1; i <= 9; i++) {
            dfs(n - 1, k, i, res);
        }
        return res;
    }

private:
    void dfs(int n, int k, int cur, vector<int>& res) {
        if (n == 0) {
            res.push_back(cur);
            return;
        }
        int num = cur % 10;
        if (num + k < 10) {
            dfs(n - 1, k, cur * 10 + num + k, res);
        }
        if (num >= k && k != 0) {
            dfs(n - 1, k, cur * 10 + num - k, res);
        }
    }
};
