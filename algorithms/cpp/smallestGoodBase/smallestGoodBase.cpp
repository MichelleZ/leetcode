// Source: https://leetcode.com/problems/smallest-good-base/
// Author: Miao Zhang
// Date:   2021-02-15

class Solution {
public:
    string smallestGoodBase(string n) {
        long long num = stol(n);
        // n = 1 + k + k^2.....k^(m - 1)
        // i: m
        for (int i = log(num + 1) / log(2); i >= 2; i--) {
            // base k
            long long left = 2;
            long long right = pow(num, 1.0 / (i - 1)) + 1;
            while (left < right) {
                long long mid = left + (right - left) / 2;
                long long sum = 0;
                for (int j = 0; j < i; j++) {
                    sum = sum * mid + 1;
                }
                if (sum == num) return to_string(mid);
                if (sum < num) left = mid + 1;
                else right = mid;
            }
        }
        return to_string(num - 1);
    }
};
