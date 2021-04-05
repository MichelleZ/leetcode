// Source: https://leetcode.com/problems/longest-arithmetic-subsequence/
// Author: Miao Zhang
// Date:   2021-04-05

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        unordered_map<int, vector<int>> h;
        for (int i = 0; i < n; i++) {
            h[A[i]].push_back(i);
        }
        int res = 2;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int d = A[j] - A[i];
                int l = 2;
                int idx = j;
                int t = A[j] + d;
                while (h.count(t)) {
                    auto it = upper_bound(begin(h[t]), end(h[t]), idx);
                    if (it == end(h[t])) break;
                    idx = *it;
                    t += d;
                    l++;
                }
                res = max(res, l);
            }
        }
        return res;
    }
};

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        vector<short> a(begin(A), end(A));
        int n = A.size();
        const short h = *max_element(begin(a), end(a));
        vector<vector<short>> dp(n, vector<short>(2 * h + 1, 1));
        short res = 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                short d = a[i] - a[j] + h;
                dp[i][d] = dp[j][d] + 1;
                res = max(res, dp[i][d]);
            }
        }
        return res;
    }
};
