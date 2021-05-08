// Source: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
// Author: Miao Zhang
// Date:   2021-05-08

class Solution {
public:
    int maxVowels(string s, int k) {
        vector<int> cnt(128);
        cnt['a'] = cnt['e'] = cnt['i'] = cnt['o'] = cnt['u'] = 1;
        int cur = 0;
        int res = 0;
        for (int r = 0;  r < s.size(); r++) {
            if (r >= k) {
                cur -= cnt[s[r - k]];
            }
            cur += cnt[s[r]];
            res = max(res, cur);
        }
        return res;
    }
};
