// Source: https://leetcode.com/problems/largest-merge-of-two-strings/
// Author: Miao Zhang
// Date:   2021-06-03

class Solution {
public:
    string largestMerge(string word1, string word2) {
        string res;
        int w1 = word1.length(), w2 = word2.length();
        int i = 0, j = 0;
        while (i < w1 && j < w2) {
            res += word1.substr(i) > word2.substr(j) ? word1[i++] : word2[j++];
        }
        res.append(word1.substr(i));
        res.append(word2.substr(j));
        return res;
    }
};
