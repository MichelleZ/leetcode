// Source: https://leetcode.com/problems/ransom-note/
// Author: Miao Zhang
// Date:   2021-02-06

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> cnt;
        for (auto m: magazine) {
            cnt[m]++;
        }
        for (auto r: ransomNote) {
            if (cnt.find(r) == cnt.end() || cnt[r] == 0) {
                return false;
            }
            cnt[r]--;
        }
        return true;
    }
};
