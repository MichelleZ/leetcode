// Source: https://leetcode.com/problems/utf-8-validation/
// Author: Miao Zhang
// Date:   2021-02-07

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int cnt = 0;
        for (int d: data) {
            if (cnt == 0) {
                if ((d >> 3) == 0b11110) cnt = 3;
                else if ((d >> 4) == 0b1110) cnt = 2;
                else if ((d >> 5) == 0b110) cnt = 1;
                else if ((d >> 7) == 0b0) cnt = 0;
                else return false;
            } else {
                if ((d >> 6) != 0b10) return false;
                cnt--;
            }
        }
        return cnt == 0;
    }
};
