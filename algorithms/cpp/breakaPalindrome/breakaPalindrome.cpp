// Source: https://leetcode.com/problems/break-a-palindrome/
// Author: Miao Zhang
// Date:   2021-04-24

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        if (n == 1) return "";
        for (int i = 0; i < n / 2; i++) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome.back() = 'b';
        return palindrome;
    }
};
