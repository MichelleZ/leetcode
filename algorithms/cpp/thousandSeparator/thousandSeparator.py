// Source: https://leetcode.com/problems/thousand-separator/
// Author: Miao Zhang
// Date:   2021-05-15

class Solution {
public:
    string thousandSeparator(int n) {
        string res;
        int cnt = 0;
        do {
            res = to_string(n % 10) + res;
            n /= 10;
            if (++cnt % 3 == 0 and n > 0) {
                res = "." + res;
            }
        } while (n);
        return res;
    }
};
