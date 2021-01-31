// Source: https://leetcode.com/problems/nim-game/
// Author: Miao Zhang
// Date:   2021-01-31

class Solution {
public:
    bool canWinNim(int n) {
        if (n % 4 == 0) return false;
        return true;
    }
};
