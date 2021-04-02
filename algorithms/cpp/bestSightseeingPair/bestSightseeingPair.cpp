// Source: https://leetcode.com/problems/best-sightseeing-pair/
// Author: Miao Zhang
// Date:   2021-04-02

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int res = 0;
        int maxnum = 0;
        for (int i = 0; i < values.size(); i++) {
            res = max(res, maxnum + values[i] - i);
            maxnum = max(maxnum, values[i] + i);
        }
        return res;
    }
};
