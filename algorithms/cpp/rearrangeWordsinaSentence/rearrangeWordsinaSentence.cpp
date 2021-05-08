// Source: https://leetcode.com/problems/rearrange-words-in-a-sentence/
// Author: Miao Zhang
// Date:   2021-05-08

class Solution {
public:
    string arrangeWords(string text) {
        text[0] = tolower(text[0]);
        vector<string> txtlist;
        stringstream ss(text);
        string word;
        while (ss >> word) {
            txtlist.push_back(word);
        }
        stable_sort(txtlist.begin(), txtlist.end(), [&] (const string& a, const string& b) {
            return a.size() < b.size();
        });

        string res;
        for (string word: txtlist) {
            res += word;
            res += " ";
        }
        res.pop_back();
        res[0] = toupper(res[0]);
        return res;
    }
};
