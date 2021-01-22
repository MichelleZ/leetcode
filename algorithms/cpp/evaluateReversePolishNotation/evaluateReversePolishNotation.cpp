// Source: https://leetcode.com/problems/evaluate-reverse-polish-notation/
// Author: Miao Zhang
// Date:   2021-01-22

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto t: tokens) {
            if (t == "+") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(a + b);
            } else if (t == "-") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b - a);
            } else if (t == "*") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(a * b);
            } else if (t == "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b / a);
            } else {
                st.push(stoi(t));
            }
        }
        return st.top();
    }
};
