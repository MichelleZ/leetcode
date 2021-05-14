// Source: https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/
// Author: Miao Zhang
// Date:   2021-05-14

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zeros;
        for (auto& row: grid) {
            int zero = 0;
            for (int i = n - 1; i >= 0 && row[i] == 0; i--) {
                zero++;
            }
            zeros.push_back(zero);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            int j = i;
            int z = n - 1 -i;
            while (j < n && zeros[j] < z) j++;
            if (j == n) return -1;
            while (j > i) {
                zeros[j] = zeros[j - 1];
                j--;
                res++;
            }
        }
        return res;
    }
};
