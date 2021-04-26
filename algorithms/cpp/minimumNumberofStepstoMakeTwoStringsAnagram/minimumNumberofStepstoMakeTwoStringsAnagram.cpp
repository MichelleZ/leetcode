// Source: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
// Author: Miao Zhang
// Date:   2021-04-26

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> scnt(26);
        int res = 0;
        for (auto& c: s) scnt[c - 'a']++;
        for (auto& c: t) {
            if (scnt[c - 'a'] > 0) {
                scnt[c - 'a']--;
            } else {
                res++;
            }
        }
        return res;
    }
};
