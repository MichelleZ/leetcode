// Source: https://leetcode.com/problems/binary-prefix-divisible-by-5/
// Author: Miao Zhang
// Date:   2021-04-02

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> res(A.size());
        int num = 0;
        for (int i = 0; i < A.size(); i++) {
            num = (num << 1 | A[i]) % 5;
            res[i] = num == 0;
        }
        return res;
    }
};
