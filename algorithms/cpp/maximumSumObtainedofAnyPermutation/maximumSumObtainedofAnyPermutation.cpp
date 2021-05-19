// Source: https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/
// Author: Miao Zhang
// Date:   2021-05-19

class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int kMod = 1e9 + 7;
        int n = nums.size();
        vector<long> cnt(n);
        for (auto& r: requests) {
            cnt[r[0]]++;
            if (r[1] + 1 < n) cnt[r[1] + 1]--;
        }
        for (int i = 1; i < n; i++) {
            cnt[i] += cnt[i - 1];
        }

        sort(begin(cnt), end(cnt));
        sort(begin(nums), end(nums));
        long res = 0;
        for (int i = 0; i < n; i++) {
            res += nums[i] * cnt[i];
        }
        return res % kMod;
    }
};
