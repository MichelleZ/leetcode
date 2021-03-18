// Source: https://leetcode.com/problems/buddy-strings/
// Author: Miao Zhang
// Date:   2021-03-18

class Solution {
public:
    bool buddyStrings(string a, string b) {
        if (a.size() != b.size()) return false;
        vector<int> ca(26);
        vector<int> cb(26);
        int diff = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i] && diff++ > 2) return false;
            ca[a[i] - 'a']++;
            cb[b[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (diff == 0 && ca[i] > 1) return true;
            if (ca[i] != cb[i]) return false;
        }
        return diff == 2;
    }
};
