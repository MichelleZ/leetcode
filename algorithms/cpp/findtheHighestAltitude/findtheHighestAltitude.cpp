// Source: https://leetcode.com/problems/find-the-highest-altitude/
// Author: Miao Zhang
// Date:   2021-06-02

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0;
        int cur = 0;
        for (int& g: gain) {
            cur += g;
            res = max(res, cur);
        }
        return res;
    }
};
