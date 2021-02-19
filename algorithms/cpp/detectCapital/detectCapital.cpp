// Source: https://leetcode.com/problems/detect-capital/
// Author: Miao Zhang
// Date:   2021-02-19

class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = std::count_if(word.begin(), word.end(), ::isupper);
        return n == 0 || (n == 1 && isupper(word[0])) || n == word.size();
    }
};
