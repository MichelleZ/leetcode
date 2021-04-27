// Source: https://leetcode.com/problems/bulb-switcher-iii/
// Author: Miao Zhang
// Date:   2021-04-27

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int res = 0;
        int right = 0;
        for (int i = 0; i < light.size(); i++) {
            right = max(right, light[i]);
            res += right == i + 1;
        }
        return res;
    }
};
