// Source: https://leetcode.com/problems/plus-one/
// Author: Miao Zhang
// Date:   2021-01-13

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        while (n >= 0) {
            if (digits[n] < 9) {
                digits[n] += 1;
                return digits;
            }
            digits[n--] = 0;
        }
        vector<int> res(digits.size() + 1, 0);
        res[0] = 1;
        return res;
    }
};
