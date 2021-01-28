// Source: https://leetcode.com/problems/basic-calculator-ii/
// Author: Miao Zhang
// Date:   2021-01-28

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        long num = 0;
        char pre_op = '+';
        for(int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                num = 10 * num + s[i] - '0';
            }
            if (i == s.size() - 1 || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                if (pre_op == '+') st.push(num);
                else if (pre_op == '-') st.push(-num);
                else if (pre_op == '*') {
                    int num2 = st.top();
                    st.pop();
                    st.push(num2 * num);
                } else if (pre_op == '/') {
                    int num2 = st.top();
                    st.pop();
                    st.push(num2 / num);
                }
                pre_op = s[i];
                num = 0;
            }
        }
        int res = 0;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};

