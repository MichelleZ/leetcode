// Source: https://leetcode.com/problems/valid-number/
// Author: Miao Zhang
// Date:   2021-01-13

class Solution {
public:
    bool isNumber(string s) {
        if (s.empty()) {
            return false;
        }
        int i = 0, j = s.size() - 1;
        while (i <= j && s[i] == ' ') i++;
        while (j >= 0 && s[j] == ' ') j--;
        bool is_digit = false, is_dot = false, is_e = false;
        for (;i <= j; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                is_digit = true;
            } else if (s[i] == '-' || s[i] == '+') {
                if (i != 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            } else if (s[i] == '.') {
                if (is_dot || is_e) {
                    return false;
                }
                is_dot = true;
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (not is_digit || is_e) {
                    return false;
                }
                is_digit = false;
                is_e = true;
            } else {
                return false;
            }
        }
        return is_digit;
    }
};
