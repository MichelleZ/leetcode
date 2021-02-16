// Source: https://leetcode.com/problems/magical-string/
// Author: Miao Zhang
// Date:   2021-02-15

class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        int idx = 2;
        while (s.size() < n) {
            s += string(s[idx++] - '0', s.back() ^ 3);
        }
        return count(s.begin(), s.begin() + n, '1');
    }
};
