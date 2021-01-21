// Source: https://leetcode.com/problems/palindrome-partitioning/
// Author: Miao Zhang
// Date:   2021-01-20

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 0) return true;
        int l = 0;
        int r = s.size() - 1;
        while (l <= r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        dfs(s, res, {});
        return res;
    }
    
    void dfs(string s, vector<vector<string>>& res, vector<string> path) {
        if (s.empty()) {
            res.push_back(path);
            return;
        }
        for (int i = 1; i <= s.size(); i++) {
            string pre = s.substr(0, i);
            if (isPalindrome(pre)) {
                path.push_back(pre);
                dfs(s.substr(i), res, path);
                path.pop_back();
            }
        }
    }
};
