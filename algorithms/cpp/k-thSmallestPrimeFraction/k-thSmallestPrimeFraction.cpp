// Source: https://leetcode.com/problems/k-th-smallest-prime-fraction/
// Author: Miao Zhang
// Date:   2021-03-10

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double l = 0;
        double r = 1.0;
        while (l < r) {
            double m = l + (r - l) / 2;
            double max_f = 0.0;
            int total = 0;
            int x, y = 0;
            for (int i = 0, j = 1; i < n - 1; i++) {
                while (j < n && arr[i] > m * arr[j]) j++;
                if (n == j) break;
                total += (n - j);
                double f = static_cast<double>(arr[i]) / arr[j];
                if (f > max_f) {
                    x = i;
                    y = j;
                    max_f = f;
                }
            }
            if (total == k) {
                return {arr[x], arr[y]};
            } else if (total > k) {
                r = m;
            } else {
                l = m;
            }
        }
        return {};
    }
};
