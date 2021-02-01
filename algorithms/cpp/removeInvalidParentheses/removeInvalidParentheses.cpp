// Source: https://leetcode.com/problems/remove-invalid-parentheses/
// Author: Miao Zhang
// Date:   2021-02-01

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int l = 0;
        int r = 0;
        for (auto &c: s) {
            l += (c == '(');
            if (l == 0) {
                r += (c == ')');
            } else {
                l -= (c == ')');
            }
        }
        
        vector<string> res;
        dfs(s, 0, l, r, res);
        return res;
    }

private:
    bool isValid(string &s) {
        int cnt = 0;
        for (char c: s) {
            if (c == '(') cnt++;
            if (c == ')') cnt--;
            if (cnt < 0) return false;
        }
        return cnt == 0;
    }
    
    void dfs(string &s, int start, int l, int r, vector<string>& res) {
        if (l == 0 && r == 0) {
            if (isValid(s)) {
                res.push_back(s);
                return;
            }
        }
        for (int i = start; i < s.size(); i++) {
            if (i != start && s[i] == s[i - 1]) continue;
            if (s[i] == '(' || s[i] == ')') {
                string cur = s;
                cur.erase(i, 1);
                if (r > 0 && s[i] == ')') {
                    dfs(cur, i, l, r - 1, res);
                } else if (l > 0 && s[i] == '(') {
                    dfs(cur, i, l - 1, r, res);
                }
            }
        }
    }
};
