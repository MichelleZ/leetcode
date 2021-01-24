// Source: https://leetcode.com/problems/excel-sheet-column-number/
// Author: Miao Zhang
// Date:   2021-01-24

class Solution {
public:
    int titleToNumber(string s) {
        long res = 0;
        for (auto ss: s) {
            res = res * 26 + ss - 'A' + 1;
        }
        return res;
    }
};
