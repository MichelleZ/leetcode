// Source: https://leetcode.com/problems/repeated-string-match/
// Author: Miao Zhang
// Date:   2021-03-01

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int q = (b.size() - 1) / a.size() + 1;
        string tmp;
        for (int i = 0; i < q; i++) {
            tmp += a;
        }
        if (tmp.find(b) != string::npos) return q;
        if ((tmp + a).find(b) != string::npos) return q + 1;
        return -1;
    }
};
