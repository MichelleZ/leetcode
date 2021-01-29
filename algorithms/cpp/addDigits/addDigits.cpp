// Source: https://leetcode.com/problems/add-digits/
// Author: Miao Zhang
// Date:   2021-01-28

/***************************************
 *n = (a[0] * 1 + a[1] * 10 + a[2] * 100 + a[3] * 1000...a[n] * 10 ^ n)
 *m = a[0] + a[1] + a[2]...a[n]
 *n % 9 = a[0] % 9 + 1 % 9 + a[2] % 9 + 10 % 9...
 *n % 9 = a[0] % 9 + a[2] % 9...
 * n % 9 = m
***************************************/
class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return 0;
        else {
            return (num - 1) % 9 + 1;
        }
    }
};
