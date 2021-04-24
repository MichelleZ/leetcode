// Source: https://leetcode.com/problems/sort-the-matrix-diagonally/
// Author: Miao Zhang
// Date:   2021-04-24

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<deque<int>> qs(m + n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                qs[i - j + n].push_back(mat[i][j]);
            }
        }
        for (auto& q: qs) {
            sort(begin(q), end(q));
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = qs[i - j + n].front();
                qs[i - j + n].pop_front();
            }
        }
        return mat;
    }
};
