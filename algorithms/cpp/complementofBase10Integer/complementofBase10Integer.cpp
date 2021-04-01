// Source: https://leetcode.com/problems/complement-of-base-10-integer/
// Author: Miao Zhang
// Date:   2021-04-01

class Solution {
public:
    int bitwiseComplement(int N) {
        int num = 1;
        while (num < N) {
            num = (num << 1) + 1;
        }
        // num = 2 ** n - 1
        return num ^ N;
    }
};
