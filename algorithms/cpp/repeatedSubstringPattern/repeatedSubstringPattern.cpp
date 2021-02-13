// Source: https://leetcode.com/problems/repeated-substring-pattern/
// Author: Miao Zhang
// Date:   2021-02-13

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        vector<int> next(n + 1, -1);
        int i = 0;
        int j = -1;
        while (i < n) {
            if (j == -1 || s[i] == s[j]) {
                i++;
                j++;
                next[i] = j;
            } else {
                j = next[j];
            }
        }
        return next[n] > 0 && n % (n - next[n]) == 0;
    }
};
