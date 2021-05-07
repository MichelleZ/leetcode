// Source: https://leetcode.com/problems/consecutive-characters/
// Author: Miao Zhang
// Date:   2021-05-07

class Solution {
public:
    int maxPower(string s) {
        char last = '?';
        int cur = 0;
        int res = 0;
        for (char& c: s) {
            if (c != last) {
                cur = 0;
                last = c;
            }
            res = max(res, ++cur);
        }
        return res;
    }
};
