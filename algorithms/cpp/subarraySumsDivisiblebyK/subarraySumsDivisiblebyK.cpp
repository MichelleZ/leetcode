// Source: https://leetcode.com/problems/subarray-sums-divisible-by-k/
// Author: Miao Zhang
// Date:   2021-03-30

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> c(K);
        c[0] = 1;
        int res = 0;
        int sums = 0;
        for (int a: A) {
            sums = (sums + a % K + K) % K;
            res += c[sums]++;
        }
        return res;
    }
};
