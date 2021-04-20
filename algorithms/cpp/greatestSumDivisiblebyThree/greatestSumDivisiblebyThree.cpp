// Source: https://leetcode.com/problems/greatest-sum-divisible-by-three/
// Author: Miao Zhang
// Date:   2021-04-20

/*************************************************
 * dp[i]: i = 0, 1, 2 mod val
 * dp[(cursum + num) % 3] = max(dp[(cursum + num) % 3], cursum + num)
*************************************************/
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3);
        for (int num: nums) {
            vector<int> tmp(dp);
            for (auto t: tmp) {
                dp[(t + num) % 3] = max(dp[(t + num) % 3], t + num);
            }
        }
        return dp[0];
    }
};
