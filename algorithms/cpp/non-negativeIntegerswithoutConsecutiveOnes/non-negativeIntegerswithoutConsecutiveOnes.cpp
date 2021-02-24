// Source: https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/
// Author: Miao Zhang
// Date:   2021-02-24

/*************************************************
 * k = 4, 0000-1111
 * 0000      1000
 *      f(3)      f(2)
 * 0100      1010
 * f(4) = f(2) + f(3)
 * num -> k=4 11.... f(4)
              10.... f(3) + part(f2)
*************************************************/
class Solution {
public:
    int findIntegers(int num) {
        vector<int> dp(31);
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i < 31; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        int hi, res = 0;
        while (num) {
            hi = 31 - __builtin_clz(num);
            res += dp[hi];
            num ^= 1 << hi;
            if (hi >= 1 && num >= (1 << (hi - 1)))
                return res + dp[hi - 1];
        }
        return res + 1;
    }
};
