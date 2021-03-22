// Source: https://leetcode.com/problems/sum-of-subsequence-widths/
// Author: Miao Zhang
// Date:   2021-03-22

class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        long kMod = 1000000007;
        int n = A.size();
        sort(begin(A), end(A));
        long res = 0;
        long p = 1;
        for (int i = 0; i < n; i++) {
            res = (res + (A[i] - A[n - i - 1]) * p) % kMod;
            p = (p << 1) % kMod;
        }
        return (res + kMod) % kMod;
    }
};
