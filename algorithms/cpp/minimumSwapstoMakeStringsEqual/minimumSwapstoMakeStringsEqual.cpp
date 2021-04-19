// Source: https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/
// Author: Miao Zhang
// Date:   2021-04-19

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xy = 0;
        int yx = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] == 'x' && s2[i] == 'y') ++xy;
            if (s1[i] == 'y' && s2[i] == 'x') ++yx;
        }
        if ((xy + yx) % 2) return -1;
        return xy / 2 + yx / 2 + xy % 2 + yx % 2;
    }
};
