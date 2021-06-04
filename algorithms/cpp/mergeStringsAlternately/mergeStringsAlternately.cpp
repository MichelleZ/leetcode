// Source: https://leetcode.com/problems/merge-strings-alternately/
// Author: Miao Zhang
// Date:   2021-06-04

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        int w1 = word1.length();
        int w2 = word2.length();
        int i = 0, j = 0;
        while (i < w1 && j < w2) {
            res += word1[i++];
            res += word2[j++];
        }
        if (i < w1) res += word1.substr(i);
        if (j < w2) res += word2.substr(j);
        return res;
    }
};
