// Source: https://leetcode.com/problems/reshape-the-matrix/
// Author: Miao Zhang
// Date:   2021-02-23

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (nums.empty()) return nums;
        int m = nums.size();
        int n = nums[0].size();
        if (m * n != r * c) return nums;

        vector<vector<int>> res(r, vector<int>(c));
        for (int i = 0; i < m * n; i++) {
            res[i / c][i % c] = nums[i / n][i % n];
        }
        return res;
    }
};
