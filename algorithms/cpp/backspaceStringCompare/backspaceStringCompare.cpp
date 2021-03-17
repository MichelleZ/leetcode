// Source: https://leetcode.com/problems/backspace-string-compare/
// Author: Miao Zhang
// Date:   2021-03-17

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<int> st1;
        stack<int> st2;
        for (auto& s: S) {
            if (s == '#') {
                if (!st1.empty()) st1.pop();
            }
            else {
                st1.push(s);
            }
        }
        for (auto& t: T) {
            if (t == '#') {
                if (!st2.empty()) st2.pop();
            }
            else {
                st2.push(t);
            }
        }
        return st1 == st2;
    }
};
