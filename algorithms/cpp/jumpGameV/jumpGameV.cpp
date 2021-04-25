// Source: https://leetcode.com/problems/jump-game-v/
// Author: Miao Zhang
// Date:   2021-04-25

/********************************************
 * dp[i] = 1 or max(dp[j]) + 1 if i can jump to j
********************************************/
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> m(n);
        function<int(int)> dp = [&] (int i) {
            if (m[i]) return m[i];
            int res = 1;
            for (int j = i + 1; j < min(n, i + d + 1) && arr[i] > arr[j]; j++)
                res = max(res, dp(j) + 1);
            for (int j = i - 1; j >= max(0, i - d) && arr[i] > arr[j]; j--)
                res = max(res, dp(j) + 1);
            return m[i] = res;
        };
        int res = 0;
        for (int i = 0; i < arr.size(); i++) {
            res = max(res, dp(i));
        }
        return res;
    }
};
