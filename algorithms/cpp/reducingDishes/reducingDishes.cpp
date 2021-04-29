// Source: https://leetcode.com/problems/reducing-dishes/
// Author: Miao Zhang
// Date:   2021-04-29

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(rbegin(satisfaction), rend(satisfaction));
        int presum = 0;
        int res = 0;
        for (int s: satisfaction) {
            if (presum + s > 0) {
                presum += s;
                res += presum;
            } else {
                break;
            }
        }
        return res;
    }
};
