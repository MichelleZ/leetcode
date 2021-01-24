// Source: https://leetcode.com/problems/fraction-to-recurring-decimal/
// Author: Miao Zhang
// Date:   2021-01-24

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long n = numerator;
        long long d = denominator;
        map<long long, int> m;
        string res;
        if (n * d < 0) res = "-";
        n = abs(n);
        d = abs(d);
        res += to_string(n / d);
        n %= d;
        if (!n) {
            return res;
        }
        
        res += ".";
        while (n) {
            if (m.count(n)) {
                res.insert(m[n], "(");
                res.push_back(')');
                break;
            }
            m[n] = res.size();
            res += n * 10 / d + '0';
            n = n * 10 % d;
        }
        return res;
    }
};
