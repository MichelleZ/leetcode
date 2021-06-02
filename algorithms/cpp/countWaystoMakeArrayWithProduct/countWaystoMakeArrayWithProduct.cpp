// Source: https://leetcode.com/problems/count-ways-to-make-array-with-product/
// Author: Miao Zhang
// Date:   2021-06-02

/***************************************************************
 * dp(n, k) = sum(dp(n - 1, i)) i is factor of k
 * dp(0, 1) = 1, dp(0, *) = 0
 * dp(i, 1) = C(n, i)
***************************************************************/
class Solution {
public:
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        int kMod = 1e9 + 7;
        int n = 0;
        unordered_map<int, int> c, dp;
        function<int(int, int)> cnk = [&] (int n, int k) {
            if (k > n) return 0;
            if (k == 0 || k == n) return 1;
            int& res = c[(n << 16) | k];
            if (!res) res = (cnk(n - 1, k - 1) + cnk(n - 1, k)) % kMod;
            return res;
        };
        function<int(int, int)> dfs = [&] (int s, int k) -> int {
            if (s == 0) return k == 1 ? 1 : 0;
            if (k == 1) return cnk(n, s);
            int& res = dp[(s << 16) | k];
            if (res) return res;
            for (int i = 1; i * i <= k; i++) {
                if (k % i) continue;
                if (i != 1) {
                    res = (res + dfs(s - 1, k / i)) % kMod;
                }
                if (i * i != k) {
                    res = (res + dfs(s - 1, i)) % kMod;
                }
            }
            return res;
        };
        vector<int> res;
        for (auto& q: queries) {
            dp.clear();
            n = q[0];
            res.push_back(dfs(q[0], q[1]));
        }
        return res;
    }
};
