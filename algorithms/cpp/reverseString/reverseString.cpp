// Source: https://leetcode.com/problems/reverse-string/
// Author: Miao Zhang
// Date:   2021-02-03

class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--) {
            swap(s[i], s[j]);
        }
    }
};
