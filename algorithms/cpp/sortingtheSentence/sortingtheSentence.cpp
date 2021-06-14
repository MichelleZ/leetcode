// Source: https://leetcode.com/problems/sorting-the-sentence/
// Author: Miao Zhang
// Date:   2021-06-14

class Solution {
public:
    string sortSentence(string s) {
        vector<pair<int, string>> tmp;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            cout << word[word.length() - 1] << endl;
            int idx = word[word.length() - 1] - 1;
            tmp.push_back({idx, word.substr(0, word.length() - 1)});
        }
        sort(begin(tmp), end(tmp));
        string res = tmp[0].second;
        for (int i = 1; i < tmp.size(); i++) {
            res += " " + tmp[i].second;
        }
        return res;
    }
};
