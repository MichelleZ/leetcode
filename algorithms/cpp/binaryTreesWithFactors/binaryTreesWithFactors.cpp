// Source: https://leetcode.com/problems/binary-trees-with-factors/
// Author: Miao Zhang
// Date:   2021-03-15

/*************************************************
 * dp[c] = sum(dp[a]*dp[b]), c = a * b
 * dp[i] = sum(dp[j] * dp[i/j])
*************************************************/
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int kMod = 1000000007;
        std::sort(arr.begin(), arr.end());
        unordered_map<int, long> dp;
        for (int i = 0; i < arr.size(); i++) {
            dp[arr[i]] = 1;
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0 && dp.count(arr[i] / arr[j])) {
                    dp[arr[i]] += (dp[arr[j]] * dp[arr[i] /arr[j]]) % kMod;
                }
            }
        }
        long res = 0;
        for (auto& kv: dp) {
            res += kv.second;
        }
        return res % kMod;
    }
};
