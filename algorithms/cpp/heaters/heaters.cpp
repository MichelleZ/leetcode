// Source: https://leetcode.com/problems/heaters/
// Author: Miao Zhang
// Date:   2021-02-15

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n = heaters.size();
        int j = 0;
        int res = 0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        for (int h: houses) {
            auto pos = lower_bound(heaters.begin(), heaters.end(), h);
            int dist1 = (pos == heaters.end()) ? INT_MAX: *pos - h;
            int dist2 = (pos == heaters.begin()) ? INT_MAX : h - *(--pos);
            res = max(res, min(dist1, dist2));
        }
        return res;
    }
};
