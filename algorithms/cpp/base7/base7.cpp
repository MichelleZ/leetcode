// Source: https://leetcode.com/problems/base-7/
// Author: Miao Zhang
// Date:   2021-02-19

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        bool is_nagetive = num < 0;
        num = abs(num);
        string res;
        while (num > 0) {
            res += ('0' + num % 7);
            num /= 7;
        }
        if (is_nagetive) {
            res += '-';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
