// Source: https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
// Author: Miao Zhang
// Date:   2021-04-01

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int res = INT_MAX;
        for (int r = 1; r <= 6; r++) {
            bool flag = true;
            int cnta = 0;
            int cntb = 0;
            for (int i = 0; i < A.size(); i++) {
                if (A[i] != r && B[i] != r) {
                    flag = false;
                    break;
                }
                else if (A[i] == r && B[i] == r) continue;
                else if (A[i] == r) {
                    cnta++;
                } else if (B[i] == r) {
                    cntb++;
                }
            }
            if (flag) res = min(res, min(cnta, cntb));
        }
        return res == INT_MAX ? -1 : res;
    }
};
