// Source: https://leetcode.com/problems/first-unique-character-in-a-string/
// Author: Miao Zhang
// Date:   2021-02-06

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> count;
        for (auto ss: s) {
            count[ss] += 1;
        }
        for (int i = 0; i < s.size(); i++) {
            if (count[s[i]] == 1) return i;
        }
        return -1;
    }
};
