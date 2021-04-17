// Source: https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/
// Author: Miao Zhang
// Date:   2021-04-17

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd = 0;
        int even = 0;
        for (int p: position) {
            if (p % 2)
                odd++;
            else
                even++;
        }
        return min(odd, even);
    }
};
