// Source: https://leetcode.com/problems/diagonal-traverse-ii/
// Author: Miao Zhang
// Date:   2021-05-06

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<vector<int>> m;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                if (m.size() <= i + j) m.push_back({});
                m[i + j].push_back(nums[i][j]);
            }
        }
        vector<int> res;
        for (int i = 0; i < m.size(); i++) {
            res.insert(end(res), rbegin(m[i]), rend(m[i]));
        }
        return res;
    }
};
