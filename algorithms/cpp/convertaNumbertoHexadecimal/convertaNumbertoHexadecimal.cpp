// Source: https://leetcode.com/problems/convert-a-number-to-hexadecimal/
// Author: Miao Zhang
// Date:   2021-02-08

const char dic[] = "0123456789abcdef";
class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        long t = num < 0 ? (1LL << 32) + num : num;
        string res;
        while (t) {
            res = dic[t % 16] + res;
            t /= 16;
        }
        return res;
    }
};
