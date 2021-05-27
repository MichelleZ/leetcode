// Source: https://leetcode.com/problems/minimum-moves-to-make-array-complementary/
// Author: Miao Zhang
// Date:   2021-05-27

/*****************************************************
 * (, 1 + a) 2
 * (1 + a, a + b) 1
 * (a + b) 0
 * (a + b, b + limit) 1
 * (b + limit + 1, ) 2
*****************************************************/
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> delta(limit * 2 + 2);
        for (int i = 0; i < n / 2; i++) {
            int a = min(nums[i], nums[n - i - 1]);
            int b = max(nums[i], nums[n - i - 1]);
            delta[a + 1]--;
            delta[a + b]--;
            delta[a + b + 1]++;
            delta[b + limit + 1]++;
        }
        int res = n;
        int cur = n;
        for (int i = 2; i <= limit * 2; i++) {
            cur += delta[i];
            res = min(res, cur);
        }
        return res;
    }
};
