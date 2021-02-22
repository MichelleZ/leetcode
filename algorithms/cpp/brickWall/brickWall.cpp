// Source: https://leetcode.com/problems/brick-wall/
// Author: Miao Zhang
// Date:   2021-02-22

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int res = 0;
        unordered_map<int, int> dict;
        for (auto &row: wall) {
            int sums = 0;
            for (int i = 0; i < row.size() - 1; i++) {
                sums += row[i];
                dict[sums]++;
                res = max(res, dict[sums]);
            }
        }
        return wall.size() - res;
    }
};
