// Source: https://leetcode.com/problems/most-visited-sector-in-a-circular-track/
// Author: Miao Zhang
// Date:   2021-05-15

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> res;
        int start = rounds[0];
        int end = rounds.back();
        if (start <= end) {
            for (int i = start; i <= end; i++) {
                res.push_back(i);
            }
        } else {
            for (int i = 1; i <= end; i++) {
                res.push_back(i);
            }
            for (int i = start; i <= n; i++) {
                res.push_back(i);
            }
        }
        return res;
    }
};
