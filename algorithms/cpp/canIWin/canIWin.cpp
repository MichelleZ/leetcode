// Source: https://leetcode.com/problems/can-i-win/
// Author: Miao Zhang
// Date:   2021-02-14

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sums = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if (sums < desiredTotal) return false;
        if (desiredTotal <= 0) return true;
        visited_ = vector<char>(1 << maxChoosableInteger, 0);
        return canWin(maxChoosableInteger, desiredTotal, 0);
    }

private:
    vector<char> visited_;
    bool canWin(int maxChoosableInteger, int desiredTotal, int state) {
        if (desiredTotal <= 0) return false;
        if (visited_[state]) return visited_[state] == 1;
        for (int i = 0; i < maxChoosableInteger; i++) {
            if (state & (1 << i)) continue;
            if (!canWin(maxChoosableInteger, desiredTotal - (i + 1), state | (1 << i))) {
                return visited_[state] = 1;
            }
        }
        visited_[state] = -1;
        return false;
    }
};
