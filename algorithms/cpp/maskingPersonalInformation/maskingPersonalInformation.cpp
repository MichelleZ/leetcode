// Source: https://leetcode.com/problems/masking-personal-information/
// Author: Miao Zhang
// Date:   2021-03-16

class Solution {
public:
    string maskPII(string S) {
        string res = "", str = "";
        auto pos = S.find('@');
        if (pos == string::npos) {
            for (char c: S) {
                if (c >= '0' && c <= '9') str.push_back(c);
            }
            int n = str.size();
            if (n > 10) res += "+" + string(n - 10, '*') + "-";
            res += "***-***-" + str.substr(n - 4);
        } else {
            res = S.substr(0, 1) + "*****" + S.substr(pos - 1);
            transform(res.begin(), res.end(), res.begin(), ::tolower);
        }
        return res;
    }
};
