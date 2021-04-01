// Source: https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
// Author: Miao Zhang
// Date:   2021-04-01

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> cnt(60);
        int res = 0;
        for (int t: time) {
            t %= 60;
            res += cnt[(60 - t) % 60];
            cnt[t]++;
        }
        return res;
    }
};
