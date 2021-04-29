// Source: https://leetcode.com/problems/longest-happy-string/
// Author: Miao Zhang
// Date:   2021-04-29

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int total = a + b + c;
        vector<int> cnt{a, b, c};
        vector<int> used{0, 0, 0};
        string res;
        for (int _ = 0; _ < total; _++) {
            for (int i = 0; i < 3; i++) {
                int j = (i + 1) % 3;
                int k = (i + 2) % 3;
                if ((cnt[i] >= cnt[j] && cnt[i] >= cnt[k] && used[i] != 2) || (cnt[i] > 0 && (used[j] == 2 || used[k] == 2))) {
                    res += i + 'a';
                    used[i]++;
                    cnt[i]--;
                    used[j] = used[k] = 0;
                    break;
                }
            }
        }
        return res;
    }
};
