// Source: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
// Author: Miao Zhang
// Date:   2021-04-06

class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;
        for (char c: S) {
            if (!st.empty() && st.top() == c) st.pop();
            else st.push(c);
        }
        string res = "";
        while(!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};
