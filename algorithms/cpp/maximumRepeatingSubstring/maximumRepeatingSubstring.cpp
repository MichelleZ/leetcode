// Source: https://leetcode.com/problems/maximum-repeating-substring/
// Author: Miao Zhang
// Date:   2021-05-26

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        string s(word);
        for (int i = 1;;i++) {
            if (sequence.find(s) == string::npos)
                return i - 1;
            s += word;
        }
        return -1;
    }
};
