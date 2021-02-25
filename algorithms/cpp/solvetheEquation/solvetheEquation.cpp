// Source: https://leetcode.com/problems/solve-the-equation/
// Author: Miao Zhang
// Date:   2021-02-25

class Solution {
public:
    string solveEquation(string equation) {
        auto parse = [](string_view s) -> vector<int> {
            int a{0}, b{0};
            int sign = 1;
            long num = 0;
            bool digit = false;
            for (char c: s) {
                if (isdigit(c)) {
                    digit = true;
                    num = num * 10 + c - '0';
                } else {
                    if (c == 'x') {
                        a += (digit ? num : 1) * sign;
                    } else {
                        b += num * sign;
                        sign = c == '+' ? 1: -1;
                    }
                    digit = false;
                    num = 0;
                }
            }
            b += num * sign;
            return {a, b};
        };

        auto pos = equation.find('=');
        auto l = parse(string_view(equation).substr(0, pos));
        auto r = parse(string_view(equation).substr(pos + 1));
        l[0] -= r[0];
        r[1] -= l[1];
        if (l[0] == 0) return r[1] == 0 ? "Infinite solutions" : "No solution";
        return "x=" + to_string(r[1] / l[0]);
    }
};
