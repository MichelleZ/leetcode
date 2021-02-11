// Source: https://leetcode.com/problems/find-all-anagrams-in-a-string/
// Author: Miao Zhang
// Date:   2021-02-11

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        vector<int> plist(26, 0);
        vector<int> slist(26, 0);
        for (char c: p) plist[c - 'a']++;
        for (int i = 0; i < s.size(); i++) {
            if (i >= p.size()) slist[s[i - p.size()] - 'a']--;
            slist[s[i] - 'a']++;
            if (slist == plist) res.push_back(i + 1 - p.size());
        }
        return res;
    }
};
