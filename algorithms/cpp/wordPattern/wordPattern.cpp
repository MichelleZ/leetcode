// Source: https://leetcode.com/problems/word-pattern/
// Author: Miao Zhang
// Date:   2021-01-30

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> pdict;
        unordered_map<string, int> sdict;
        istringstream in(s);
        int i = 0;
        for (string word; in >> word; i++) {
            if (i == pattern.size() || pdict[pattern[i]] != sdict[word]) 
                return false;
            // i + 1, eg. 'm' not in pdict, but pdict['m'] = 0
            pdict[pattern[i]] = sdict[word] = i + 1;
        }
        return i == pattern.size();
    }
};
