// Source: https://leetcode.com/problems/super-egg-drop/
// Author: Miao Zhang
// Date:   2021-03-22

class Solution {
public:
    int superEggDrop(int k, int n) {
        m_ = vector<vector<int>>(k + 1, vector<int>(n + 1, INT_MIN));
        return dp(k, n);
    }

private:
    vector<vector<int>> m_;

    int dp(int k, int n) {
        if (k <= 0) return 0;
        if (k == 1) return n;
        if (n <= 1) return n;
        if (m_[k][n] != INT_MIN) return m_[k][n];
        int l = 1;
        int r = n + 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            int broken = dp(k - 1, m - 1);
            int unbroken = dp(k, n - m);
            if (broken >= unbroken) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return m_[k][n] = 1 + dp(k - 1, l - 1);
    }
};
