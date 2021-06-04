// Source: https://leetcode.com/problems/longest-nice-substring/
// Author: Miao Zhang
// Date:   2021-06-04

class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.length();
        string res;
        for (int i = 0; i < n; i++) {
            vector<int> u(26), l(26);
            for (int j = i; j < n; j++) {
                char c = s[j];
                if (isupper(c)) u[c - 'A'] = 1;
                else l[c - 'a'] = 1;
                if (u == l &&  j - i + 1 > res.length())
                    res = s.substr(i, j - i + 1);
            }
        }
        return res;
    }
};
