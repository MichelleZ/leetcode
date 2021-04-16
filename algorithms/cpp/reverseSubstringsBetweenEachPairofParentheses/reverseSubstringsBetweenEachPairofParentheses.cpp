// Source: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
// Author: Miao Zhang
// Date:   2021-04-16

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        st.push("");
        for (char c: s) {
            if (c == '(') st.push("");
            else if (c != ')') st.top() += c;
            else {
                string t = st.top(); st.pop();
                st.top().insert(end(st.top()), rbegin(t), rend(t));
            }
        }
        return st.top();
    }
};
