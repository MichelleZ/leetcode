// Source: https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/
// Author: Miao Zhang
// Date:   2021-05-12

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int kMod = 1e9 + 7;
        vector<int> sums;
        for (int i = 0; i < nums.size(); i++) {
            int s = 0;
            for (int j = i; j < nums.size(); j++) {
                s += nums[j];
                sums.push_back(s);
            }
        }
        sort(begin(sums), end(sums));
        return accumulate(begin(sums) + left - 1, begin(sums) + right, 0LL) % kMod;
    }
};
