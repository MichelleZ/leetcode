// Source: https://leetcode.com/problems/arithmetic-slices/
// Author: Miao Zhang
// Date:   2021-02-09

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0;
        int cur = 0;
        for (int i = 2; i < A.size(); i++) {
            if (A[i - 1] - A[i - 2] == A[i] - A[i - 1]) {
                res += ++cur;
            } else {
                cur = 0;
            }
        }
        return res;
    }
};
