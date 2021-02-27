// Source: https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/
// Author: Miao Zhang
// Date:   2021-02-27

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 1;
        int r = m * n + 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (counter(m, n, mid) >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    int counter(int m, int n, int mid) {
        int cnt = 0;
        for (int i = 1; i <= m; i++) {
            cnt += min(n, mid / i);
        }
        return cnt;
    }
};
