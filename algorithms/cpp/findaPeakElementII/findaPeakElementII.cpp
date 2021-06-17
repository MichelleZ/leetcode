// Source: https://leetcode.com/problems/find-a-peak-element-ii/
// Author: Miao Zhang
// Date:   2021-06-17

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int l = 0;
        int r = m - 1;

        auto findMax = [&] (int k) {
            vector<int> ans(2);
            ans[0] = k;
            int up = k - 1 >= 0 ? k - 1: k;
            int down = k + 1 < m ? k + 1: k;
            for (int i = up; i <= down; i++) {
                for (int j = 0; j < n; j++) {
                    if (mat[ans[0]][ans[1]] < mat[i][j]) {
                        ans[0] = i;
                        ans[1] = j;
                    }
                }
            }
            return ans;
        };

        vector<int> res(2);
        while (l < r) {
            int mid = l + (r - l) / 2;
            res = findMax(mid);
            if (res[0] == mid) {
                return res;
            } else if (res[0] < mid) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};
