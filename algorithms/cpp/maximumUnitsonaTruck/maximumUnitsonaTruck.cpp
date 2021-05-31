// Source: https://leetcode.com/problems/maximum-units-on-a-truck/
// Author: Miao Zhang
// Date:   2021-05-31

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(begin(boxTypes), end(boxTypes), [] (auto& b1, auto& b2) {
            return b1[1] > b2[1];
        });

        int res = 0;
        for (auto& b: boxTypes) {
            res += (b[1] * min(b[0], truckSize));
            if ((truckSize -= b[0]) <= 0) break;
        }
        return res;
    }
};
