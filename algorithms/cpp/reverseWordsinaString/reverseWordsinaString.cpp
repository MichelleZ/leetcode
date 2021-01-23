// Source: https://leetcode.com/problems/reverse-words-in-a-string/
// Author: Miao Zhang
// Date:   2021-01-22

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string res;
        while (ss >> word) {
            res = word + " " + res;
        }
        
        return res.substr(0, res.size() - 1);
    }
};
