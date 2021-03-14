// Source: https://leetcode.com/problems/ambiguous-coordinates/
// Author: Miao Zhang
// Date:   2021-03-14

class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        vector<string> res;
        S = S.substr(1, S.size() - 2);
        for (int i = 1; i < S.size() + 1; i++) {
            vector<string> left = make(S.substr(0, i));
            vector<string> right = make(S.substr(i));
            if (left.size() != 0 && right.size() != 0) {
                for (auto l: left) {
                    for (auto r: right) {
                        res.push_back("(" + l + ", " + r + ")");
                    }
                }
            }
        }
        return res;
    }

private:
    bool isvalid(string s) {
        return s[s.size() - 1] != '0';
    }
    
    vector<string> make(string s) {
        if (s.size() == 0) return {};
        if (s.size() < 2) return {s};
        if (s[0] == '0') {
            int i = 0;
            while (s[i] == '0') {
                i++;
            }
            if (i == s.size()) {
                if (s.size() == 1) {
                    return {s};
                } else {
                    return {};
                }
            }
            if (isvalid(s)) {
                return {s.substr(0, 1) + "." + s.substr(1)};
            } else {
                return {};
            }
        } else {
            vector<string> res;
            for (int i = 1; i < s.size(); i++) {
                if (isvalid(s.substr(i))) {
                    res.push_back(s.substr(0, i) + "." + s.substr(i));
                }
            }
            res.push_back(s);
            return res;
        }
    }
};
