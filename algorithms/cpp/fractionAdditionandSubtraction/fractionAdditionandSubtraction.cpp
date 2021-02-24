// Source: https://leetcode.com/problems/fraction-addition-and-subtraction/
// Author: Miao Zhang
// Date:   2021-02-24

class Solution {
public:
    string fractionAddition(string expression) {
        // a / b + c / d
        // ad * bc / bd
        int a = 0;
        int b = 1;
        int c;
        int d;
        char slash;
        istringstream in(expression);
        while (in >> c >> slash >> d) {
            a = a * d + b * c;
            b *= d;
            int gcd = abs(__gcd(a, b));
            a /= gcd;
            b /= gcd;
        }
        return to_string(a) + "/" + to_string(b);
    }
};
