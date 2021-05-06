// Source: https://leetcode.com/problems/minimum-number-of-frogs-croaking/
// Author: Miao Zhang
// Date:   2021-05-06

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        vector<int> idx(26);
        idx['c' - 'a'] = 0;
        idx['r' - 'a'] = 1;
        idx['o' - 'a'] = 2;
        idx['a' - 'a'] = 3;
        idx['k' - 'a'] = 4;
        vector<int> cnt(5);
        int cur = 0;
        int res = 0;
        for (char c: croakOfFrogs) {
            int i = idx[c - 'a'];
            cnt[i]++;
            if (c == 'c') {
                res = max(res, ++cur);
                continue;
            }
            if (cnt[i] > cnt[i - 1]) return -1;
            if (c == 'k') cur--;
        }
        return cur ? -1 : res;
    }
};
