// Source: https://leetcode.com/problems/valid-parentheses/
// Author: Miao Zhang
// Date:   2021-01-06

class Solution {
public:
    bool isValid(string s) {
        map<char, char> m{{')', '('}, {'}', '{'}, {']', '['}};
        stack<char> st;
        for (auto c: s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else if (c == ')' || c == '}' || c == ']' ) {
                if (st.empty() || st.top() != m[c]) return false;
                st.pop();
            } else {
                return false;
            }
        }
        return st.empty();
    }
};
