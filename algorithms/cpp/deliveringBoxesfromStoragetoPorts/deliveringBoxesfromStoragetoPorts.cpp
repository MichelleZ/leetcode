// Source: https://leetcode.com/problems/delivering-boxes-from-storage-to-ports/
// Author: Miao Zhang
// Date:   2021-05-27

class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n = boxes.size();
        vector<int> dp(n + 1);
        for (int l = 0, r = 0, w = 0, t = 1; r < n; r++) {
            if (r == 0 || boxes[r][0] != boxes[r - 1][0]) ++t;
            w += boxes[r][1];
            while (w > maxWeight
               || (r - l + 1) > maxBoxes
               || (l < r && dp[l + 1] == dp[l])) {
                w -= boxes[l++][1];
                if (boxes[l][0] != boxes[l - 1][0]) --t;
            }
            dp[r + 1] = dp[l] + t;
        }
        return dp[n];
    }
};
