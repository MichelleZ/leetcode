// Source: https://leetcode.com/problems/add-binary/
// Author: Miao Zhang
// Date:   2021-01-13

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string res;
        while (i >= 0 || j >= 0) {
            int c = (i >= 0 ? a[i--] - '0': 0);
            int d = (j >= 0 ? b[j--] - '0': 0);
            int s = c + d + carry;
            carry = s >> 1;
            res += '0' + (s & 1);
        }
        if (carry) res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};
