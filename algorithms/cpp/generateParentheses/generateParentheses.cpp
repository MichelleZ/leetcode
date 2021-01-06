// Source: https://leetcode.com/problems/generate-parentheses/
// Author: Miao Zhang
// Date:   2021-01-06

/***********************************************************
 * backtrack: s is the middle variable; 
 * When n = 3, left is from 0 to 2, right is from 0 to 2; 
 * left + right = 6
***********************************************************/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs("", 0, 0, n, res);
        return res;
    }
    
    void dfs(string s, int left, int right, int n, vector<string>& res) {
        if (s.size() == 2 * n) {
            res.push_back(s);
            return;
        }
        if (left < n) {
            dfs(s + '(', left + 1, right, n, res);
        }
        if (right < left) {
            dfs(s + ')', left, right + 1, n, res);
        }
    }
};
