// Source: https://leetcode.com/problems/minimum-number-of-refueling-stops/
// Author: Miao Zhang
// Date:   2021-03-20

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int cur = startFuel;
        int stops = 0;
        int i = 0;
        priority_queue<int> q;
        while (true) {
            if (cur >= target) return stops;
            while (i < stations.size() && stations[i][0] <= cur) {
                q.push(stations[i++][1]);
            }
            if (q.empty()) break;
            cur += q.top();
            q.pop();
            stops++;
        }
        return -1;
    }
};
