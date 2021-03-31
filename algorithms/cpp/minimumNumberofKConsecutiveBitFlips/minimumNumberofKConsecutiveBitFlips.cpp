// Source: https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/
// Author: Miao Zhang
// Date:   2021-03-31

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        vector<int> flipped(A.size());
        int res = 0;
        int flip = 0;
        for (int i = 0; i < A.size(); i++) {
            if (i >= K) flip ^= flipped[i - K];
            if ((A[i] ^ flip) == 0) {
                if (i + K > A.size()) return -1;
                res++;
                flip ^= 1;
                flipped[i] = 1;
            }
        }
        return res;
    }
};
