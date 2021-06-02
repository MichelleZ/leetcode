// Source: https://leetcode.com/problems/maximum-number-of-balls-in-a-box/
// Author: Miao Zhang
// Date:   2021-06-02

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        vector<int> balls(46);
        int res = 0;
        for (int i = lowLimit; i <= highLimit; i++) {
            int n = i;
            int sums = 0;
            while (n) {
                sums += n % 10;
                n /= 10;
            }
            res = max(res, ++balls[sums]);
        }
        return res;
    }
};
