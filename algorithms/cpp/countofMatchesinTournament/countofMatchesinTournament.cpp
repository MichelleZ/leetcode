// Source: https://leetcode.com/problems/count-of-matches-in-tournament/
// Author: Miao Zhang
// Date:   2021-05-28

class Solution {
public:
    int numberOfMatches(int n) {
        int res = 0;
        while (n > 1) {
            res += n / 2 + (n & 1);
            n /= 2;
        }
        return res;
    }
};
