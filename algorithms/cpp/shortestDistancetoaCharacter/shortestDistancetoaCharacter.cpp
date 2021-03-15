// Source: https://leetcode.com/problems/shortest-distance-to-a-character/
// Author: Miao Zhang
// Date:   2021-03-14

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> res(n, INT_MAX);
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == c) idx = i;
            if (idx < 0) continue;
            res[i] = abs(i - idx);
        }
        idx = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == c) idx = i;
            if (idx < 0) continue;
            res[i] = min(res[i], abs(i - idx));
        }
        return res;
    }
};
