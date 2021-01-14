// Source: https://leetcode.com/problems/minimum-window-substring/
// Author: Miao Zhang
// Date:   2021-01-14

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> dicts;
        int i;
        for (i = 0; i < t.size(); i++) {
            if (dicts.find(t[i]) == dicts.end()) {
                dicts[t[i]] = 1;
            } else dicts[t[i]]++;
        }
        string res;
        int count = 0;
        int l = 0;
        int minlen = s.size() + 1;
        for (i = 0; i < s.size(); i++) {
            if (dicts.find(s[i]) != dicts.end()) {
                dicts[s[i]]--;
                if (dicts[s[i]] >= 0) count++;
                while (count == t.size()) {
                    if (minlen > i - l + 1) {
                        minlen = i - l + 1;
                        res = s.substr(l, i + 1 - l);
                    }
                    if (dicts.find(s[l]) != dicts.end()) {
                        dicts[s[l]]++;
                        if (dicts[s[l]] > 0) count--;
                    }
                    l++;
                }
            }
        }
        return res;
    }
};
