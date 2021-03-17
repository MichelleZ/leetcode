// Source: https://leetcode.com/problems/find-and-replace-in-string/
// Author: Miao Zhang
// Date:   2021-03-16

class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        vector<pair<int, int>> idx;
        for (int i = 0; i < indexes.size(); i++) {
            idx.emplace_back(indexes[i], i);
        }
        sort(idx.rbegin(), idx.rend());
        for (auto id: idx) {
            int i = id.first;
            string s = sources[id.second];
            string t = targets[id.second];
            if (S.substr(i, s.size()) == s) {
                S = S.substr(0, i) + t + S.substr(i + s.size());
            }
        }
        return S;
    }
};
