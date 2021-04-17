// Source: https://leetcode.com/problems/count-vowels-permutation/
// Author: Miao Zhang
// Date:   2021-04-17

/*******************************************************
 * dp[i][x] = length of i, ends with x
 * dp[1][*] = 1
 * res = sum(dp[n])
 * a: dp[i - 1]
 * aa: dp[i]
*******************************************************/
class Solution {
public:
    int countVowelPermutation(int n) {
        int kMod = 1e9 + 7;
        long a = 1, e = 1, i = 1, o = 1, u = 1;
        for (int k = 2; k <= n; k++) {
            long aa = (e + i + u) % kMod;
            long ee = (a + i) % kMod;
            long ii = (e + o) % kMod;
            long oo = i % kMod;
            long uu = (i + o) % kMod;
            a = aa;
            e = ee;
            i = ii;
            o = oo;
            u = uu;
        }
        return (a + e + i + o + u) % kMod;
    }
};
