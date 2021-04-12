// Source: https://leetcode.com/problems/number-of-equivalent-domino-pairs/
// Author: Miao Zhang
// Date:   2021-04-12

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> num(100);
        int res = 0;
        for (const auto& d: dominoes) {
            int val = d[0] <= d[1] ? d[0] * 10 + d[1] : d[1] * 10 + d[0];
            res += num[val];
            num[val]++;
        }
        return res;
    }
};
