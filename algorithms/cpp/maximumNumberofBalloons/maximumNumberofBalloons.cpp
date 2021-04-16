// Source: https://leetcode.com/problems/maximum-number-of-balloons/
// Author: Miao Zhang
// Date:   2021-04-16

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int> cnt;
        for (char t: text) cnt[t]++;
        return min({cnt['b'], cnt['a'], cnt['l'] / 2, cnt['o'] / 2, cnt['n']});
    }
};
