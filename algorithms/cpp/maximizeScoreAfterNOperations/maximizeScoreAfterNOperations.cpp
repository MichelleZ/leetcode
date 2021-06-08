// Source: https://leetcode.com/problems/maximize-score-after-n-operations/
// Author: Miao Zhang
// Date:   2021-06-08

class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> cache(1 << n, vector<int>(n / 2 + 1));
        function<int(int, int)> dp = [&] (int mask, int k) {
            if (mask == 0) return 0;
            int& res = cache[mask][k];
            if (res > 0) return res;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if ((mask & (1 << i)) && (mask & (1 << j))) {
                        res = max(res, k * gcd(nums[i], nums[j]) +
                                  dp(mask ^ (1 << i) ^ (1 << j), k + 1));
                    }
                }
            }
            return res;
        };
        return dp((1 << n) - 1, 1);
    }
};
