// Source: https://leetcode.com/problems/valid-palindrome-ii/
// Author: Miao Zhang
// Date:   2021-03-01

class Solution {
public:
    bool validPalindrome(string s) {
        int l = -1;
        int r = s.size();
        while (++l < -- r) {
            if (s[l] != s[r]) {
                return isPalindrome(s, l + 1, r)
                       || isPalindrome(s, l, r - 1);
            }
        }
        return true;
    }

private:
    bool isPalindrome(const string& s, int l , int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
};
