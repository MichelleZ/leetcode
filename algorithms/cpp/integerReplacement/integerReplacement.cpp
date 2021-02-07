// Source: https://leetcode.com/problems/integer-replacement/
// Author: Miao Zhang
// Date:   2021-02-07

class Solution {
public:
    int integerReplacement(int n) {
        int res = 0;
        long num = n;
        while (num > 1) {
            res++;
            if (num & 1) {
                if (num & 2 && num != 3) {
                    num++;
                } else {
                    num--;
                }
            } else {
                num >>= 1;
            }
        }
        return res;
    }
};
