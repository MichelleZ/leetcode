// Source: https://leetcode.com/problems/time-needed-to-inform-all-employees/
// Author: Miao Zhang
// Date:   2021-04-28

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> es(n);
        for (int i = 0; i < n; i++) {
            if (i != headID)
                es[manager[i]].push_back(i);
        }

        function<int(int)> dfs = [&] (int cur) {
            int res = 0;
            for (int e: es[cur]) {
                res = max(res, dfs(e));
            }
            return res + informTime[cur];
        };
        return dfs(headID);
    }
};
