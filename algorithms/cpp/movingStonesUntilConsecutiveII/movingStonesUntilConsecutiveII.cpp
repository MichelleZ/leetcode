// Source: https://leetcode.com/problems/moving-stones-until-consecutive-ii/
// Author: Miao Zhang
// Date:   2021-04-06

class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(begin(stones), end(stones));
        int n = stones.size();
        int i = 0;
        int low = n;
        for (int j = 0; j < n; j++) {
            while (stones[j] - stones[i] + 1 > n) i++;
            int already_stone = j - i + 1;
            if (already_stone == n - 1 && stones[j] - stones[i] + 1 == n - 1) {
                low = min(low, 2);
            } else {
                low = min(low, n - already_stone);
            }
        }
        return {low, max(stones[n - 1] - stones[1] - n + 2, stones[n - 2] - stones[0] - n + 2)};
    }
};
