// Source: https://leetcode.com/problems/largest-substring-between-two-equal-characters/
// Author: Miao Zhang
// Date:   2021-05-24

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> m(26, -1);
        int res = -1;
        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            if (m[idx] == -1) {
                m[idx] = i;
            } else {
                res = max(res, i - m[idx] - 1);
            }
        }
        return res;
    }
};
