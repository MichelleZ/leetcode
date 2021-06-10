// Source: https://leetcode.com/problems/find-the-winner-of-the-circular-game/
// Author: Miao Zhang
// Date:   2021-06-10

class Solution {
public:
    int findTheWinner(int n, int k) {
        return f(n, k) + 1;
    }

    int f(int n, int k) {
        if (n == 1) return 0;
        return (f(n - 1, k) + k) % n;
    }
};
