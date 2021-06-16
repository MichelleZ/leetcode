// Source: https://leetcode.com/problems/check-if-word-equals-summation-of-two-words/
// Author: Miao Zhang
// Date:   2021-06-16

class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        auto transfer = [] (const string& s) -> int {
            int res = 0;
            for (char c: s) {
                res *= 10;
                res += c - 'a';
            }
            return res;
        };
        return transfer(firstWord) + transfer(secondWord) == transfer(targetWord);
    }
};
