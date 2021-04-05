// Source: https://leetcode.com/problems/divisor-game/
// Author: Miao Zhang
// Date:   2021-04-05

class Solution {
public:
    bool divisorGame(int n) {
        cache_ = vector<int>(n + 1, -1);
        return canWin(n);
    }

private:
    vector<int> cache_;
    bool canWin(int n) {
        if (n == 1) return false;
        if (cache_[n] != -1) return cache_[n];
        bool win = false;
        for (int i = 1; i < sqrt(n) + 1; i++) {
            if (n % i == 0) {
                win |= !canWin(n - i);
            }
        }
        return cache_[n] = win;
    }
};
