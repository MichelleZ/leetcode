// Source: https://leetcode.com/problems/make-the-string-great/
// Author: Miao Zhang
// Date:   2021-05-14

class Solution {
public:
    string makeGood(string s) {
        string st;
        for (char c: s) {
            if (st.length() && abs(st.back() - c) == abs('a' - 'A')) {
                st.pop_back();
            } else {
                st.push_back(c);
            }
        }
        return st;
    }
};
