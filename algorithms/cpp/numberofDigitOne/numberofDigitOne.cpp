// Source: https://leetcode.com/problems/number-of-digit-one/
// Author: Miao Zhang
// Date:   2021-01-28

class Solution {
public:
    int countDigitOne(int n) {
        int cnt = 0;
        for (long i = 1; i <= n; i *= 10) {
            int a = n / i;
            int b = n % i;
            if (a % 10 == 0) cnt += a / 10 * i;
            else if (a % 10 == 1) cnt += a / 10 * i + (b + 1);
            else cnt += (a / 10 + 1) * i;
        }
        return cnt;
    }
};
