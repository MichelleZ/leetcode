// Source: https://leetcode.com/problems/number-of-provinces/
// Author: Miao Zhang
// Date:   2021-02-21

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (isConnected[i][i]) {
                res++;
                dfs(isConnected, i, n);
            }
        }
        return res;
    }
    
    void dfs(vector<vector<int>>& isConnected, int cur, int n) {
        for (int i = 0; i < n; i++) {
            if (isConnected[cur][i] == 1) {
                isConnected[cur][i] = isConnected[i][cur] = 0;
                dfs(isConnected, i, n);
            }
        }
    }
};
