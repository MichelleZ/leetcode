// Source: https://leetcode.com/problems/isomorphic-strings/
// Author: Miao Zhang
// Date:   2021-01-25

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m1;
        unordered_map<char, char> m2;
        for (int i = 0; i < s.size(); i++) {
            if (m1.find(s[i]) == m1.end()) {
                m1[s[i]] = t[i];
            } else if (m1[s[i]] != t[i]) {
                return false;
            }
            if (m2.find(t[i]) == m2.end()) {
                m2[t[i]] = s[i];
            } else if (m2[t[i]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};
