// Source: https://leetcode.com/problems/determine-if-string-halves-are-alike/
// Author: Miao Zhang
// Date:   2021-05-29

class Solution {
public:
    bool halvesAreAlike(string s) {
        auto cnt = [] (string s) {
            int res = 0;
            for (char& c: s) {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                    res++;
                }
            }
            return res;
        };
        int n = s.length();
        return cnt(s.substr(0, n / 2)) == cnt(s.substr(n / 2));
    }
};
