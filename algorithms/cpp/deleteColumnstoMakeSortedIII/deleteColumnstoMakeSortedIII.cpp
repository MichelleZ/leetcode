// Source: https://leetcode.com/problems/delete-columns-to-make-sorted-iii/
// Author: Miao Zhang
// Date:   2021-03-29

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                bool valid = true;
                for (auto& s: strs) {
                    if (s[j] > s[i]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return n - *max_element(begin(dp), end(dp));
    }
};
