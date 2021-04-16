// Source: https://leetcode.com/problems/make-array-strictly-increasing/
// Author: Miao Zhang
// Date:   2021-04-16

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int kInf = 1e9;
        int m = arr1.size();
        sort(begin(arr2), end(arr2));
        arr2.resize(unique(begin(arr2), end(arr2)) - begin(arr2));
        int n = arr2.size();

        vector<int> keep(m, kInf);
        keep[0] = 0;
        vector<vector<int>> swap(m, vector<int>(n, kInf));
        fill(begin(swap[0]), end(swap[0]), 1);

        for (int i = 1; i < m; i++) {
            int minkeep = kInf;
            int minswap = kInf;
            for (int j = 0; j < n; j++) {
                if (j > 0) minswap = min(minswap, swap[i - 1][j - 1] + 1);
                if (arr1[i] > arr2[j]) minkeep = min(minkeep, swap[i - 1][j]);
                if (arr1[i] > arr1[i - 1]) keep[i] = keep[i - 1];
                if (arr2[j] > arr1[i - 1]) swap[i][j] = keep[i - 1] + 1;
                swap[i][j] = min(swap[i][j], minswap);
                keep[i] = min(keep[i], minkeep);
            }
        }
        int s = *min_element(begin(swap.back()), end(swap.back()));
        int k = keep.back();
        int res = min(s, k);
        return res >= kInf ? -1: res;
    }
};
