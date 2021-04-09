// Source: https://leetcode.com/problems/filling-bookcase-shelves/
// Author: Miao Zhang
// Date:   2021-04-09

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n = books.size();
        vector<int> dp(n, INT_MAX / 2);
        for (int j = 0; j < n; j++) {
            int w = 0;
            int h = 0;
            for (int i = j; i >= 0; i--) {
                if ((w += books[i][0]) > shelf_width) break;
                h = max(h, books[i][1]);
                dp[j] = min(dp[j], (i == 0 ? 0: dp[i - 1]) + h);
            }
        }
        return dp.back();
    }
};
