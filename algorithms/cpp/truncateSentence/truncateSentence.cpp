// Source: https://leetcode.com/problems/truncate-sentence/
// Author: Miao Zhang
// Date:   2021-06-09

class Solution {
public:
    string truncateSentence(string s, int k) {
        string res;
        stringstream ss(s);
        for (int i = 0; i < k && ss; i++) {
            string word;
            ss >> word;
            res += (res.empty() ? "" : " ") + word;
        }
        return res;
    }
};
