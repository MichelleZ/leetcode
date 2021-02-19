// Source: https://leetcode.com/problems/relative-ranks/
// Author: Miao Zhang
// Date:   2021-02-19

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int, int>> s;
        for (int i = 0; i < score.size(); i++) {
            s.emplace_back(score[i], i);
        }
        vector<string> medals{"Gold", "Silver", "Bronze"};
        std::sort(s.rbegin(), s.rend());
        vector<string> res(s.size());
        for (int i = 0; i < s.size(); i++) {
            res[s[i].second] = i < 3 ? (medals[i] + " Medal") : std::to_string(i + 1);
        }
        return res;
    }
};
