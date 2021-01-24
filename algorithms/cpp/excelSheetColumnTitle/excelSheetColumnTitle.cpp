// Source: https://leetcode.com/problems/excel-sheet-column-title/
// Author: Miao Zhang
// Date:   2021-01-24

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while (n != 0) {
            res = (char)((n - 1) % 26 + 65) + res;
            n = (n - 1) / 26;
        }
        return res;
    }
};
