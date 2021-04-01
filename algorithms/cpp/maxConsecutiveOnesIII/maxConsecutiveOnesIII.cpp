// Source: https://leetcode.com/problems/max-consecutive-ones-iii/
// Author: Miao Zhang
// Date:   2021-04-01

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int l = 0;
        int zeros = 0;
        int res = 0;
        for (int r = 0; r < A.size(); r++) {
            if (A[r] == 0) zeros++;
            while (zeros > K) {
                if (A[l++] == 0) zeros--;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
