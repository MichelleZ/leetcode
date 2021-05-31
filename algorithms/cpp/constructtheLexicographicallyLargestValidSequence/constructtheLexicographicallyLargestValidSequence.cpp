// Source: https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/
// Author: Miao Zhang
// Date:   2021-05-31

class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        int len = 2 * n - 1;
        vector<int> res(len);
        function<bool(int, int)> dfs = [&] (int i, int s) {
            if (i == len) return true;
            if (res[i]) return dfs(i + 1, s);
            for (int d = n; d > 0; d--) {
                int j = i + (d == 1 ? 0: d);
                if ((s & (1 << d)) || j >= len || res[j]) continue;
                res[i] = res[j] = d;
                if (dfs(i + 1, s | (1 << d))) return true;
                res[i] = res[j]= 0;
            }
            return false;
        };
        dfs(0, 0);
        return res;
    }
};
