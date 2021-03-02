// Source: https://leetcode.com/problems/stickers-to-spell-word/
// Author: Miao Zhang
// Date:   2021-03-02

class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = target.size();
            
        vector<int> dp((1 << n), -1);
        dp[0] = 0;
        for (int state = 0; state < (1 << n); state++) {
            if (dp[state] == -1) continue;
            for (string sticker: stickers) {
                int now = state;
                for (char c: sticker) {
                    for (int i = 0; i < n; i++) {
                        if ((now >> i) & 1 == 1) continue;
                        if (c == target[i]) {
                            now |= (1 << i);
                            break;
                        }
                    }
                }
                if (dp[now] == -1 || dp[now] > dp[state] + 1) {
                    dp[now] = dp[state] + 1;
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};
