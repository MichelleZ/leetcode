// Source: https://leetcode.com/problems/gas-station/
// Author: Miao Zhang
// Date:   2021-01-20

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) return -1;
        int cur_gas = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            cur_gas += gas[i] - cost[i];
            if (cur_gas < 0) {
                cur_gas = 0;
                start = i + 1;
            }
        }
        return start;
    }
};
