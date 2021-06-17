// Source: https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/
// Author: Miao Zhang
// Date:   2021-06-17

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> cnt(26, 0);
        for (auto& word: words) {
            for (char& c: word) {
                cnt[c - 'a']++;
            }
        }
        int n = words.size();
        return all_of(begin(cnt), end(cnt), [n] (int x) { return x % n == 0; });
    }
};
