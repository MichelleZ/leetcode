// Source: https://leetcode.com/problems/longest-harmonious-subsequence/
// Author: Miao Zhang
// Date:   2021-02-24

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> cnts;
        int res = 0;
        for (int n: nums) {
            cnts[n]++;
            int l = cnts[n - 1];
            int r = cnts[n + 1];
            if (l || r) {
                res = max(res, cnts[n] + max(l, r));
            }
        }
        return res;
    }
};
