// Source: https://leetcode.com/problems/length-of-last-word/
// Author: Miao Zhang
// Date:   2021-01-12

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size() - 1;
        string res;
        while (n >= 0 && s[n] == ' ') n--;
        while (n >= 0 && s[n] != ' ') {
            res.push_back(s[n]);
            n--;
        }
        reverse(res.begin(), res.end());
        return res.size();
    }
};
