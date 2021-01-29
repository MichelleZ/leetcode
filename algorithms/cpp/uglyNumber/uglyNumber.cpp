// Source: https://leetcode.com/problems/ugly-number/
// Author: Miao Zhang
// Date:   2021-01-28

class Solution {
public:
    bool isUgly(int num) {
        vector<int> factors{2, 3, 5};
        for (auto &fac: factors) {
            while (num && num % fac == 0) num /= fac;
        }
        return num == 1;
    }
};
