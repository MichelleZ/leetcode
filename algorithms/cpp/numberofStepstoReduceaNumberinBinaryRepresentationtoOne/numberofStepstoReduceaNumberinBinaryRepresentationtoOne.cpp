// Source: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/
// Author: Miao Zhang
// Date:   2021-04-29

class Solution {
public:
    int numSteps(string s) {
        int res = 0;
        int carry = 0;
        for (int i = s.length() - 1; i > 0; i--) {
            if (s[i] - '0' + carry == 1) {
                res += 2;
                carry = 1;
            } else {
                res++;
            }
        }
        return res + carry;
    }
};
