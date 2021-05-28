// Source: https://leetcode.com/problems/maximum-height-by-stacking-cuboids/
// Author: Miao Zhang
// Date:   2021-05-28

class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        cuboids.push_back({0, 0, 0});
        int n = cuboids.size();
        vector<int> dp(n);
        for (auto& c: cuboids) sort(begin(c), end(c));
        sort(begin(cuboids), end(cuboids));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (cuboids[i][0] >= cuboids[j][0] && cuboids[i][1] >= cuboids[j][1] && cuboids[i][2] >= cuboids[j][2]) {
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
        }
        return *max_element(begin(dp), end(dp));
    }
};
