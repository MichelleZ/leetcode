// Source: https://leetcode.com/problems/defanging-an-ip-address/
// Author: Miao Zhang
// Date:   2021-04-09

class Solution {
public:
    string defangIPaddr(string address) {
        string res;
        for (char c: address) {
            if (c == '.') res += "[.]";
            else res += c;
        }
        return res;
    }
};
