// Source: https://leetcode.com/problems/find-longest-awesome-substring/
// Author: Miao Zhang
// Date:   2021-05-14

class Solution {
public:
    int longestAwesome(string s) {
        int kInf = 1e9;
        vector<int> idx(1024, kInf);
        idx[0] = -1;
        int mask = 0;
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            mask ^= (1 << (s[i] - '0'));
            res = max(res, i - idx[mask]);
            for (int j = 0; j < 10; j++) {
                res = max(res, i - idx[mask ^ (1 << j)]);
            }
            idx[mask] = min(idx[mask], i);
        }
        return res;
    }
};
