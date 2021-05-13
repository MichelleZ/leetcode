// Source: https://leetcode.com/problems/number-of-substrings-with-only-1s/
// Author: Miao Zhang
// Date:   2021-05-12

class Solution {
public:
    int numSub(string s) {
        int kMod = 1e9 + 7;
        long res = 0;
        int cur = 0;
        for (char c: s) {
            cur = c == '1' ? cur + 1 : 0;
            res += cur;
        }
        return res % kMod;
    }
};
