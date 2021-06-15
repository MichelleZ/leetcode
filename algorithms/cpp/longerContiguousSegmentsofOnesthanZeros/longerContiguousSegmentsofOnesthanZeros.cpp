// Source: https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/
// Author: Miao Zhang
// Date:   2021-06-15

class Solution {
public:
    bool checkZeroOnes(string s) {
        if (s.empty()) return false;
        int ones = 0, zeros = 0, lenones = 0, lenzeros = 0;
        for (int i = 0; i < s.length();) {
            if (s[i] == '1') {
                zeros = i + 1;
                i++;
                lenones = max(lenones, i - ones);
            } else {
                ones = i + 1;
                i++;
                lenzeros = max(lenzeros, i - zeros);
            }
        }
        return lenones > lenzeros ? true : false;
    }
};
