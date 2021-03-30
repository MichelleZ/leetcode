// Source: https://leetcode.com/problems/string-without-aaa-or-bbb/
// Author: Miao Zhang
// Date:   2021-03-30

class Solution {
public:
    string strWithout3a3b(int a, int b) {
        char s1 = 'a';
        char s2 = 'b';
        if (b > a) {
            swap(s1, s2);
            swap(a, b);
        }
        string res;
        while (a || b) {
            if (a > 0) {
                res += s1;
                a--;
            }
            if (a > b) {
                res += s1;
                a--;
            }
            if (b > 0) {
                res += s2;
                b--;
            }
        }
        return res;
    }
};
