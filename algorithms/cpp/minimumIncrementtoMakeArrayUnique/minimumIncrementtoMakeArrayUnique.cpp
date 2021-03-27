// Source: https://leetcode.com/problems/minimum-increment-to-make-array-unique/
// Author: Miao Zhang
// Date:   2021-03-27

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int res = 0;
        sort(begin(A), end(A));
        for (int i = 1; i < A.size(); i++) {
            if (A[i] > A[i - 1]) continue;
            res += (A[i - 1] - A[i]) + 1;
            A[i] = A[i - 1] + 1;
        }
        return res;
    }
};
