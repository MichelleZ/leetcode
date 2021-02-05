// Source: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
// Author: Miao Zhang
// Date:   2021-02-05

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0];
        int r = matrix[n - 1][n - 1];
        while (l < r) {
            int mid = l + (r - l) / 2;
            int total = 0;
            int s = n;
            for (auto& row: matrix) {
                total += (s = distance(begin(row), upper_bound(begin(row), begin(row) + s, mid)));
            }
            if (total < k) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
