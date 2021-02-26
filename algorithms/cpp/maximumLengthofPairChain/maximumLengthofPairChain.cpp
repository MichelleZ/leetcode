// Source: https://leetcode.com/problems/maximum-length-of-pair-chain/
// Author: Miao Zhang
// Date:   2021-02-26

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int cur = INT_MIN;
        int res = 0;
        sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
            return (a[1] < b[1]) || (a[1] == b[1] && a[0] < b[0]);
        });

        for (auto& p: pairs) {
            if (cur < p[0]) {
                cur = p[1];
                res++;
            }
        }
        return res;
    }
};
