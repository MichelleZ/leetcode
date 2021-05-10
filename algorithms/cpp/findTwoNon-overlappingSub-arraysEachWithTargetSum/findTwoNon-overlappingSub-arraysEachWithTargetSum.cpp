// Source: https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/
// Author: Miao Zhang
// Date:   2021-05-10

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int kInf = 1e9;
        int n = arr.size();
        vector<int> minlens(n, kInf);
        int res = kInf;
        int l = 0;
        int minlen = kInf;
        int sums = 0;
        for (int r = 0; r < n; r++) {
            sums += arr[r];
            while (sums > target) sums -= arr[l++];
            if (sums == target) {
                int curlen = r - l + 1;
                if (l > 0 && minlens[l - 1] != kInf) {
                    res = min(res, curlen + minlens[l - 1]);
                }
                minlen = min(minlen, curlen);
            }
            minlens[r] = minlen;
        }
        return res >= kInf ? -1: res;
    }
};
