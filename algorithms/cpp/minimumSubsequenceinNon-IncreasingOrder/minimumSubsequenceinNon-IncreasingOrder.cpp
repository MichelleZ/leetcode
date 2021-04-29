// Source: https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/
// Author: Miao Zhang
// Date:   2021-04-29

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(rbegin(nums), rend(nums));
        int total = accumulate(begin(nums), end(nums), 0);
        vector<int> res;
        int sums = 0;
        for (int n: nums) {
            sums += n;
            res.push_back(n);
            if (sums > total / 2) break;
        }
        return res;
    }
};
