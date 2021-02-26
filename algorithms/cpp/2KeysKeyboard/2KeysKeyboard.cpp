// Source: https://leetcode.com/problems/2-keys-keyboard/
// Author: Miao Zhang
// Date:   2021-02-26

class Solution {
public:
    int minSteps(int n) {
        int res = 0;
        int i = 2;
        while (n > 1) {
            while (n % i == 0) {
                res += i;
                n /= i;
            }
            i++;
        }
        return res;
    }
};
