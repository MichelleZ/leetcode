// Source: https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/
// Author: Miao Zhang
// Date:   2021-04-27

class Solution {
public:
    string generateTheString(int n) {
        if (n % 2) {
            return string(n, 'a');
        }
        return string(n - 1, 'a') + 'b';
    }
};
