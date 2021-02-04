// Source: https://leetcode.com/problems/russian-doll-envelopes/
// Author: Miao Zhang
// Date:   2021-02-04

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<int> dp;
        sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        for (int i = 0; i < envelopes.size(); i++) {
            auto it = lower_bound(dp.begin(), dp.end(), envelopes[i][1]);
            if (it == dp.end()) dp.push_back(envelopes[i][1]);
            else *it = envelopes[i][1];
        }
        return dp.size();
    }
};
