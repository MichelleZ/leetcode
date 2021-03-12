// Source: https://leetcode.com/problems/number-of-lines-to-write-string/
// Author: Miao Zhang
// Date:   2021-03-12

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1;
        int units = 0;
        for (char c: s) {
            if (units + widths[c - 'a'] > 100) {
                lines++;
                units = 0;
            }
            units += widths[c - 'a'];
        }
        return {lines, units};
    }
};
