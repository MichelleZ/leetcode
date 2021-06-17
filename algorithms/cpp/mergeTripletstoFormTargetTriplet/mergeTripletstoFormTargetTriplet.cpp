// Source: https://leetcode.com/problems/merge-triplets-to-form-target-triplet/
// Author: Miao Zhang
// Date:   2021-06-17

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int x = target[0], y = target[1], z = target[2];
        int i = 0, j = 0, k = 0;
        for (auto& t: triplets) {
            if (t[0] <= x && t[1] <= y && t[2] <= z) {
                tie(i, j, k) = tuple(max(i, t[0]), max(j, t[1]), max(k, t[2]));
            }
        }
        return tie(i, j, k) == tie(x, y, z);
    }
};
