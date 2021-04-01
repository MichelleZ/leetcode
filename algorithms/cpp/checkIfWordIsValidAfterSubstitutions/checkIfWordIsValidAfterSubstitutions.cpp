// Source: https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/
// Author: Miao Zhang
// Date:   2021-04-01

class Solution {
public:
    bool isValid(string s) {
        string stack;
        for (int i = 0; i < s.length(); i++) {
            stack += s[i];
            int n = stack.size();
            if (n >= 3 && stack[n - 3] == 'a' && stack[n - 2] == 'b' && stack[n - 1] == 'c') {
                stack.resize(n - 3);
            }
        }
        return stack.empty();
    }
};
