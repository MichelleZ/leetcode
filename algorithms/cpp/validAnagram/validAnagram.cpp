// Source: https://leetcode.com/problems/valid-anagram/
// Author: Miao Zhang
// Date:   2021-01-28

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> dic;
        for (auto ss: s) {
            if (dic.find(ss) == dic.end()) dic[ss] = 1;
            else dic[ss]++;
        }
        for (auto tt: t) {
            if (dic.find(tt) == dic.end()) dic[tt] = 1;
            else dic[tt]--;
        }
        for (auto d: dic) {
            if (d.second != 0) return false;
        }
        return true;
    }
};
