// Source: https://leetcode.com/problems/split-two-strings-to-make-palindrome/
// Author: Miao Zhang
// Date:   2021-05-20

class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        auto isPalindrome = [] (string& s, int i, int j) {
            while (i < j && s[i] == s[j]) {
                i++;
                j--;
            }
            return i >= j;
        };
        auto check = [&] (string& a, string& b) {
            int i = 0;
            int j = a.length() - 1;
            while (i < a.length() && j >= 0 && a[i] == b[j]) {
                i++;
                j--;
            }
            return isPalindrome(a, i, j) || isPalindrome(b, i, j);
        };
        return check(a, b) || check(b, a);
    }
};
