// Source: https://leetcode.com/problems/flipping-an-image/
// Author: Miao Zhang
// Date:   2021-03-16

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (auto& row: image) reverse(row.begin(), row.end());
        for (auto& row: image) {
            for (auto& num: row) num ^= 1;
        }
        return image;
    }
};
