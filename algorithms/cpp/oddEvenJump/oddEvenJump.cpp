// Source: https://leetcode.com/problems/odd-even-jump/
// Author: Miao Zhang
// Date:   2021-03-30

class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        map<int, int> m;
        vector<vector<int>> dp(n, vector<int>(2));
        dp[n - 1][0] = dp[n - 1][1] = 1;
        m[arr[n - 1]] = n - 1;
        int res = 1;
        for (int i = n - 2; i >= 0; i--) {
            auto o = m.lower_bound(arr[i]);
            if (o != m.end()) dp[i][0] = dp[o->second][1];
            auto e = m.upper_bound(arr[i]);
            if (e != m.begin()) dp[i][1] = dp[prev(e)->second][0];
            if (dp[i][0]) res++;
            m[arr[i]] = i;
        }
        return res;
    }
};
