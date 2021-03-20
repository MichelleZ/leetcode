// Source: https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/
// Author: Miao Zhang
// Date:   2021-03-20

/*****************************************************
 * dp[j][k] = dp[i][j] + 1, arr[i] + arr[j] = arr[k]
*****************************************************/
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[arr[i]] = i;
        }
        vector<vector<int>> dp(n , vector<int>(n, 2));
        int res = 0;
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int arri = arr[k] - arr[j];
                if (arri >= arr[j]) break;
                auto it = m.find(arri);
                if (it == m.end()) continue;
                int i = it->second;
                dp[j][k] = dp[i][j] + 1;
                res = max(res, dp[j][k]);
            }
        }
        return res;
    }
};
