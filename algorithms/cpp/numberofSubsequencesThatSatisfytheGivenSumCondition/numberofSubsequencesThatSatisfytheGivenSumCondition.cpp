// Source: https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
// Author: Miao Zhang
// Date:   2021-05-11

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int kMod = 1e9 + 7;
        int n = nums.size();
        vector<int> cnt(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            cnt[i] = (cnt[i - 1] << 1) % kMod;
        }
        sort(begin(nums), end(nums));
        int res = 0;
        for (int i = 0, j = n - 1; i <= j; i++) {
            while (i <= j && nums[i] + nums[j] > target) j--;
            if (i > j) continue;
            res = (res + cnt[j - i]) % kMod;
        }
        return res;
    }
};
