// Source: https://leetcode.com/problems/maximum-population-year/
// Author: Miao Zhang
// Date:   2021-06-14

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> year(2051);
        for (auto& log: logs) {
            for (int i = log[0]; i < log[1]; i++) {
                year[i]++;
            }
        }
        int res = -1;
        int maxval = 0;
        for (int i = 1950; i < 2051; i++) {
            if (year[i] > maxval) {
                maxval = year[i];
                res = i;
            }
        }
        return res;
    }
};
