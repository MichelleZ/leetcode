// Source: https://leetcode.com/problems/numbers-at-most-n-given-digit-set/
// Author: Miao Zhang
// Date:   2021-03-23

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        int len = s.size();
        int res = 0;
        for (int i = 1; i < len; i++) {
            res += pow(digits.size(), i);
        }
        for (int i = 0; i < len; i++) {
            bool prefix = false;
            for (const string& d: digits) {
                if (d[0] < s[i]) {
                    res += pow(digits.size(), len - i - 1);
                } else if (d[0] == s[i]) {
                    prefix = true;
                    break;
                }
            }
            if (!prefix) return res;
        }
        return res + 1;
    }
};
