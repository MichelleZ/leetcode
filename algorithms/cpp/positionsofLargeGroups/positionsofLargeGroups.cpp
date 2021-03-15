// Source: https://leetcode.com/problems/positions-of-large-groups/
// Author: Miao Zhang
// Date:   2021-03-15

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> res;
        int start = 0;
        for (int i = 1; i <= s.size(); i++) {
            if (i == s.size() || s[i] != s[i - 1]) {
                if (i - start >= 3) {
                    res.push_back({start, i - 1});
                }
                start = i;
            }
        }
        return res;
    }
};
