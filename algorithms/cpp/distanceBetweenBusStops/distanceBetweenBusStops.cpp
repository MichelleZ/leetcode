// Source: https://leetcode.com/problems/distance-between-bus-stops/
// Author: Miao Zhang
// Date:   2021-04-16

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if (start > destination) swap(start, destination);
        int sum = accumulate(begin(distance), end(distance), 0);
        int d1 = accumulate(begin(distance) + start, begin(distance) + destination, 0);
        return min(d1, sum - d1);
    }
};
