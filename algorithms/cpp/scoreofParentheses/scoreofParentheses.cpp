// Source: https://leetcode.com/problems/score-of-parentheses/
// Author: Miao Zhang
// Date:   2021-03-18

class Solution {
public:
    int scoreOfParentheses(string S) {
        return score(S, 0, S.length() - 1);
    }

private:
    int score(const string& S, int l, int r) {
        if (r - l == 1) return 1; // ()
        int n = 0;
        for (int i = l; i < r; i++) {
            if (S[i] == '(') n++;
            if (S[i] == ')') n--;
            if (n == 0) {
                return score(S, l, i) + score(S, i + 1, r);
            }
        }
        return 2 * score(S, l + 1, r - 1);
    }
};
