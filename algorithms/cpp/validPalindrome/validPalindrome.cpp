// Source: https://leetcode.com/problems/valid-palindrome/
// Author: Miao Zhang
// Date:   2021-01-19

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        int l = 0;
        int r = s.size() - 1;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        while (l < r) {
            if (!isalnum(s[l])) l++;
            else if (!isalnum(s[r])) r--;
            else if(s[l] != s[r]) return false;
            else l++, r--;
        }
        return true;
    }
};
