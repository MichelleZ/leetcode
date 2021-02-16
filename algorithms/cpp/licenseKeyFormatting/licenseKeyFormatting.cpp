// Source: https://leetcode.com/problems/license-key-formatting/
// Author: Miao Zhang
// Date:   2021-02-15

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string s;
        for (char c: S) {
            if (c != '-') s.push_back(toupper(c));
        }
        string res = s.substr(0, s.size() % K);
        for (int i = s.size() % K; i < s.size(); i+= K) {
            if (i != 0) res += '-';
            res += s.substr(i, K);
        }
        return res;
    }
};
