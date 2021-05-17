// Source: https://leetcode.com/problems/find-latest-group-of-size-m/
// Author: Miao Zhang
// Date:   2021-05-16

class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        vector<int> len(n + 2);
        vector<int> cnt(n + 2);
        int res = -1;
        for (int i = 0; i < n; i++) {
            int x = arr[i];
            int l = len[x - 1];
            int r = len[x + 1];
            int t = 1 + l + r;
            len[x - l] = len[x + r] = t;
            cnt[l]--;
            cnt[r]--;
            cnt[t]++;
            if (cnt[m])
                res = i + 1;
        }
        return res;
    }
};
