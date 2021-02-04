// Source: https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/
// Author: Miao Zhang
// Date:   2021-02-04

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int res = INT_MIN;
        for (int l = 0; l < n; l++) {
            vector<int> sum(m);
            for (int r = l; r < n; r++) {
                for (int k = 0; k < m; k++) {
                    sum[k] += matrix[k][r];
                }
                int prefix_sum = 0;
                set<int> st{0};
                for (auto n: sum) {
                    prefix_sum += n;
                    auto it = st.lower_bound(prefix_sum - k);
                    if (it != st.end()) {
                        res = max(res, prefix_sum - *it);
                    }
                    st.insert(prefix_sum);
                }
            }
        }
        return res;
    }
};
