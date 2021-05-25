// Source: https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
// Author: Miao Zhang
// Date:   2021-05-25

class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26);
        for (char c: s) freq[c - 'a']++;
        unordered_set<int> seen;
        int res = 0;
        for (int f: freq) {
            while (f && !seen.insert(f).second) {
                f--;
                res++;
            }
        }
        return res;
    }
};
