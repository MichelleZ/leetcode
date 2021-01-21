// Source: https://leetcode.com/problems/word-break-ii/
// Author: Miao Zhang
// Date:   2021-01-21

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        map<string, vector<string>> dicts;
        return wordBreak(s, wordDict, dicts);
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict, map<string, vector<string>> dicts) {
        if (dicts.count(s)) return dicts[s];
        if (s.empty()) return {""};
        vector<string> res;
        for (auto word: wordDict) {
            if (s.substr(0, word.size()) != word) continue;
            vector<string> tmp = wordBreak(s.substr(word.size()), wordDict, dicts);
            for (auto str: tmp) {
                res.push_back(word + (str.empty() ? "" : " " + str));
            }
        }
        dicts[s] = res;
        return res;
    }
};
