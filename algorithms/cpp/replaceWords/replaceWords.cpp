// Source: https://leetcode.com/problems/replace-words/
// Author: Miao Zhang
// Date:   2021-02-26

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> rootset(begin(dictionary), end(dictionary));
        string res;
        istringstream is(sentence);
        string cur;
        while (is >> cur) {
            string word;
            for (auto& c: cur) {
                word += c;
                if (rootset.count(word)) {
                    cur = word;
                    break;
                }
            }
            res += cur + ' ';
        }
        res.pop_back();
        return res;
    }
};
