// Source: https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
// Author: Miao Zhang
// Date:   2021-04-13

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> cnt(26);
        for (char c: chars) cnt[c - 'a']++;
        int res = 0;
        for (string& word: words) {
            vector<int> cur(26);
            bool valid = true;
            for (char w: word) {
                if (++cur[w - 'a'] > cnt[w - 'a']) {
                    valid = false;
                    break;
                }
            }
            if (valid) res += word.size();
        }
        return res;
    }
};
