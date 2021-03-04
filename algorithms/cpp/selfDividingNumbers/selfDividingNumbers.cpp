// Source: https://leetcode.com/problems/self-dividing-numbers/
// Author: Miao Zhang
// Date:   2021-03-04

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int n = left; n <= right; n++) {
            int x = n;
            bool valid = true;
            while (x && valid) {
                int r = x % 10;
                if (r == 0 or n % r) valid = false;
                x /= 10;
            }
            if (valid) res.push_back(n);
        }
        return res;
    }
};
