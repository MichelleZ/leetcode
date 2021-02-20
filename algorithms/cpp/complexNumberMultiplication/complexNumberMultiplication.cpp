// Source: https://leetcode.com/problems/complex-number-multiplication/
// Author: Miao Zhang
// Date:   2021-02-20

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        istringstream is1(a), is2(b);
        int a1, a2, b1, b2, r1, r2;
        char plus;
        is1 >> a1 >> plus >> a2;
        is2 >> b1 >> plus >> b2;
        r1 = a1 * b1 - a2 * b2;
        r2 = a1 * b2 + a2 * b1;
        return to_string(r1) + "+" + to_string(r2) + "i";
    }
};
