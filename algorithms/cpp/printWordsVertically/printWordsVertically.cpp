// Source: https://leetcode.com/problems/print-words-vertically/
// Author: Miao Zhang
// Date:   2021-04-23

class Solution {
public:
    vector<string> printVertically(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;
        int maxlen = 0;
        while (ss >> word) {
            words.push_back(word);
            maxlen = max(maxlen, (int)word.size());
        }
        
        vector<string> res;
        // row
        for (int i = 0; i < maxlen; i++) {
            string tmp;
            for (string& word: words) {
                tmp += (i < word.size() ? word[i] : ' ');
            }
            while (tmp.back() == ' ') tmp.pop_back();
            res.push_back(tmp);
        }
        return res;
    }
};
