// Source: https://leetcode.com/problems/number-of-segments-in-a-string/
// Author: Miao Zhang
// Date:   2021-02-11

class Solution {
public:
    int countSegments(string s) {
        if (s.empty()) return 0;
        int res = 0;
        int i = 0;
        while (i < s.length()) {
            while (i < s.length() && s[i] == ' ') i++;
            if (i == s.length()) break;
            while (i < s.length() && s[i] != ' ') i++;
            res++;
            i++;
        }
        return res;
    }
};
