// Source: https://leetcode.com/problems/delete-and-earn/
// Author: Miao Zhang
// Date:   2021-03-05

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        auto it = max_element(nums.begin(), nums.end());
        vector<int> num((*it) + 1, 0);
        for (int n: nums) {
            num[n - 1] += n;
        }
        return getMax(num);
    }

private:
    int getMax(const vector<int>& nums) {
        int dp2 = 0;
        int dp1 = 0;
        for (int i = 0; i < nums.size() ; ++i) {
            int dp = max(dp2 + nums[i], dp1);
            dp2 = dp1;
            dp1 = dp;
        }
        return dp1;
    }
};
