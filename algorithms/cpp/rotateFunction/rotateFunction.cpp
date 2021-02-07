// Source: https://leetcode.com/problems/rotate-function/
// Author: Miao Zhang
// Date:   2021-02-07

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        long long sums = 0;
        long long f = 0;
        int n = A.size();
        for (int i = 0; i < n; i++) {
            sums += A[i];
            f += i * A[i];
        }
        long long res = f;
        for (int i = 1; i < n; i++) {
            f = f + sums - (long long)n * A[n - i];
            res = max(res, f);
        }
        return res;
    }
};
