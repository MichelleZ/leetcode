// Source: https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/
// Author: Miao Zhang
// Date:   2021-04-05

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int n = A.size();
        vector<int> sums(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sums[i + 1] = sums[i] + A[i];
        }
        int res = 0;
        for (int i = 0; i <= n - L; i++) {
            int ls = sums[i + L] - sums[i];
            int ms = max(maxSum(sums, 0, i - M, M),
                        maxSum(sums, i + L, n - M, M));
            res = max(res, ls + ms);
        }
        return res;
    }

private:
    int maxSum(const vector<int>& sums, int s, int e, int l) {
        int res = INT_MIN;
        for (int i = s; i <= e; i++) {
            res = max(res, sums[i + l] - sums[i]);
        }
        return res;
    }
};
