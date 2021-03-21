// Source: https://leetcode.com/problems/uncommon-words-from-two-sentences/
// Author: Miao Zhang
// Date:   2021-03-21

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> m;
        string S = A + " " + B;
        istringstream words(S);
        string w;
        while (words >> w) {
            m[w]++;
        }
        vector<string> res;
        for (auto& e: m) {
            if (e.second == 1)
                res.push_back(e.first);
        }
        return res;
    }
};
