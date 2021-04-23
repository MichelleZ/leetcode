// Source: https://leetcode.com/problems/maximum-69-number/
// Author: Miao Zhang
// Date:   2021-04-23

class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '6') {
                s[i] = '9';
                break;
            }
        }
        return stoi(s);
    }
};
