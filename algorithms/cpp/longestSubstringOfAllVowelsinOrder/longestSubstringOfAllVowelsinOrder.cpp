// Source: https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/
// Author: Miao Zhang
// Date:   2021-06-11

class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n = word.length();
        int res = 0;
        char last = 'a' - 1;
        int l = 0;
        int vowels = 0;
        for (int r = 0; r < n; r++) {
            if (word[r] < last) {
                vowels = (word[r] == 'a');
                l = r;
            } else if (word[r] > last) {
                vowels++;
            }
            if (vowels == 5) {
                res = max(res, r - l + 1);
            }
            last = word[r];
        }
        return res;
    }
};
