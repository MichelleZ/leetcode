// Source: https://leetcode.com/problems/smallest-range-ii/
// Author: Miao Zhang
// Date:   2021-03-23

class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(begin(A), end(A));
        int res = A.back() - A.front();
        for (int i = 0; i < A.size() - 1; i++) {
            int a = A[i];
            int b = A[i + 1];
            res = min(res, max(A.back() - K, a + K) - min(A.front() + K, b - K));
        }
        return res;
    }
};
