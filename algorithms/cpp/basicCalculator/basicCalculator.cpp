// Source: https://leetcode.com/problems/basic-calculator/
// Author: Miao Zhang
// Date:   2021-01-27

class Solution {
public:
    int calculate(string s) {
        long res = 0;
        long num = 0;
        int sign = 1;
        stack<int> st;
        for (auto &c: s) {
            if (isdigit(c)) {
                num = num * 10 + c -'0';
            } else if (c == '+' || c == '-') {
                res += sign * num;
                num = 0;
                sign = (c == '+') ? 1: -1;
            } else if (c == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            } else if (c == ')') {
                res += sign * num;
                num = 0;
                res *= st.top();
                st.pop();
                res += st.top();
                st.pop();
            }
        }
        res += sign * num;
        return res;
    }
};
