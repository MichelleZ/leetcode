// Source: https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/
// Author: Miao Zhang
// Date:   2021-04-27

class Solution {
public:
    int findTheLongestSubstring(string s) {
        char vowels[] = "aeiou";
        vector<int> idx(1 << 5, INT_MAX);
        idx[0] = -1;
        int state = 0;
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < 5; j++) {
                if (s[i] == vowels[j])
                    state ^= 1 << j;
            }
            if (idx[state] == INT_MAX) idx[state] = i;
            res = max(res, i - idx[state]);
        }
        return res;
    }
};
