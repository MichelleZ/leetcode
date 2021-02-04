// Source: https://leetcode.com/problems/largest-divisible-subset/
// Author: Miao Zhang
// Date:   2021-02-04

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return {};
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 0);
        vector<int> parent(nums.size(), 0);
        int maxval = 0;
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if ((nums[i] % nums[j] == 0) && (dp[i] < dp[j] + 1)) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                    if (dp[i] > maxval) {
                        maxval = dp[i];
                        index = i;
                    }
                }
            }
        }
        vector<int> res;
        for (int j = 0; j <= maxval; j++) {
            res.push_back(nums[index]);
            index = parent[index];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
