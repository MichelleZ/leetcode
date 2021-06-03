// Source: https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/
// Author: Miao Zhang
// Date:   2021-06-03

class Solution {
public:
    int minOperations(string s) {
        int c1 = 0, c2 = 0;
        for (int i = 0; i < s.length(); i++) {
            c1 += (s[i] - '0' == i % 2);
            c2 += (s[i] - '0' != i % 2);
        }
        return min(c1, c2);
    }
};
