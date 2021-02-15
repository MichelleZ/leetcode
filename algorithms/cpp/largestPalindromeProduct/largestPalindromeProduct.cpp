// Source: https://leetcode.com/problems/largest-palindrome-product/
// Author: Miao Zhang
// Date:   2021-02-15

class Solution {
public:
    int largestPalindrome(int n) {
        int upper = pow(10, n) - 1;
        int lower = upper / 10;
        for (int i = upper; i > lower; i--) {
            string t = to_string(i);
            long pro = stol(t + string(t.rbegin(), t.rend()));
            for (long j = upper; j * j > pro; j--) {
                if (pro % j == 0) return pro % 1337;
            }
        }
        return 9;
    }
};
