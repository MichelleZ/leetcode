// Source: https://leetcode.com/problems/3sum-with-multiplicity/
// Author: Miao Zhang
// Date:   2021-03-25

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int maxn = 100;
        int kMod = 1e9 + 7;
        vector<long> cnt(maxn + 1, 0);
        for (int a: arr) cnt[a]++;
        long res = 0;
        for (int i = 0; i <= target; i++) {
            for (int j = i; j <= target; j++) {
                int k = target - i - j;
                if (k < 0 || k >= cnt.size() || k < j) continue;
                if (!cnt[i] || !cnt[j] || !cnt[k]) continue;
                if (i == j && j == k) {
                    res += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
                } else if (i == j && j != k) {
                    res += cnt[i] * (cnt[i] - 1) / 2 * cnt[k];
                } else if (i != j && j == k) {
                    res += cnt[i] * cnt[j] * (cnt[j] - 1) / 2;
                } else {
                    res += cnt[i] * cnt[j] * cnt[k];
                }
            }
        }
        return res % kMod;
    }
};
