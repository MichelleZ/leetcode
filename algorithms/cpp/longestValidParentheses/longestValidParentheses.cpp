// Source: https://leetcode.com/problems/longest-valid-parentheses/
// Author: Miao Zhang
// Date:   2021-01-07

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int start = 0;
        int maxlen = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (st.empty()) {
                    start = i + 1;
                } else {
                    st.pop();
                    if (st.empty()) maxlen = max(maxlen, i - start + 1);
                    else maxlen = max(maxlen, i - st.top());
                }
            }
        }
        return maxlen;
    }
};
