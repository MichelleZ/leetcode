// Source: https://leetcode.com/problems/longest-chunked-palindrome-decomposition/
// Author: Miao Zhang
// Date:   2021-04-13

class Solution {
public:
    int longestDecomposition(string text) {
        int n = text.length();
        if (n == 0) return 0;
        for (int l = 1; l <= n / 2; l++) {
            if (text.substr(0, l) == text.substr(n - l)) {
                return 2 + longestDecomposition(text.substr(l, n - 2 * l));
            }
        }
        return 1;
    }
};
