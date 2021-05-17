// Source: https://leetcode.com/problems/number-of-ways-to-split-a-string/
// Author: Miao Zhang
// Date:   2021-05-16

class Solution {
public:
    int numWays(string s) {
        int kMod = 1e9 + 7;
        long n = s.length();
        unordered_map<int, long> cnt;
        int c = 0;
        for (char ch: s) {
            if (ch == '1') c++;
            cnt[c]++;
        }
        if (c % 3 != 0) return 0;
        if (c == 0) {
            return ((n - 1) * (n - 2) / 2) % kMod;
        }
        return (cnt[c / 3] * cnt[c / 3 * 2]) % kMod;
    }
};
