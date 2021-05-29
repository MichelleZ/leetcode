// Source: https://leetcode.com/problems/maximum-binary-string-after-change/
// Author: Miao Zhang
// Date:   2021-05-29

class Solution {
public:
    string maximumBinaryString(string binary) {
        int n = binary.length();
        int leading = 0;
        int zeros = 0;
        for (char& c: binary) {
            if (c == '0') {
                zeros++;
            } else if (zeros == 0) {
                leading++;
            }
            c = '1';
        }
        if (leading != n) binary[leading + zeros - 1] = '0';
        return binary;
    }
};
