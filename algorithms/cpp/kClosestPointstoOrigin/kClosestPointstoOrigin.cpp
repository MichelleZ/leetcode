// Source: https://leetcode.com/problems/k-closest-points-to-origin/
// Author: Miao Zhang
// Date:   2021-03-30

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(begin(points), end(points), [](const vector<int>& a, const vector<int>& b) {
           return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        });
        return {points.begin(), points.begin() + k};
    }
};
