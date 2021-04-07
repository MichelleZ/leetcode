// Source: https://leetcode.com/problems/letter-tile-possibilities/
// Author: Miao Zhang
// Date:   2021-04-07

class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector<int> cnt(26, 0);
        for (char c: tiles) {
            cnt[c - 'A']++;
        }
        int res = 0;
        backtrack(cnt, res);
        return res;
    }

private:
    void backtrack(vector<int>& cnt, int& res) {
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 0) continue;
            res++;
            cnt[i]--;
            backtrack(cnt, res);
            cnt[i]++;
        }
    }
};
