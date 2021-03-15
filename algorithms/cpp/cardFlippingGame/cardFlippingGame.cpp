// Source: https://leetcode.com/problems/card-flipping-game/
// Author: Miao Zhang
// Date:   2021-03-15

class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> f;
        for (int i = 0; i < fronts.size(); i++) {
            if (fronts[i] == backs[i])
                f.insert(fronts[i]);
        }
        int res = INT_MAX;
        for (int fr: fronts) {
            if (fr < res && !f.count(fr)) {
                res = fr;
            }
        }
        for (int b: backs) {
            if (b < res && !f.count(b)) {
                res = b;
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
