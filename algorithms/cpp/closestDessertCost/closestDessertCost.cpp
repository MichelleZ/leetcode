// Source: https://leetcode.com/problems/closest-dessert-cost/
// Author: Miao Zhang
// Date:   2021-06-07

class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int m = toppingCosts.size();
        int mindiff = INT_MAX;
        int res = INT_MAX;
        function<void(int, int)> dfs = [&] (int s, int cur) {
            if (s == m) {
                for (int bc: baseCosts) {
                    int total = bc + cur;
                    int diff = abs(total - target);
                    if (diff < mindiff
                       || (diff == mindiff && total < res)) {
                        mindiff = diff;
                        res = total;
                    }
                }
                return;
            }
            for (int i = s; i < m; i++) {
                dfs(i + 1, cur);
                dfs(i + 1, cur + toppingCosts[i]);
                dfs(i + 1, cur + toppingCosts[i] * 2);
            }
        };
        dfs(0, 0);
        return res;
    }
};
