// Source: https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
// Author: Miao Zhang
// Date:   2021-05-26

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string res1, res2;
        for (string& c: word1) res1 += c;
        for (string& c: word2) res2 += c;
        return res1 == res2;
    }
};
