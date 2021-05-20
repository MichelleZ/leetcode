// Source: https://leetcode.com/problems/maximum-number-of-visible-points/
// Author: Miao Zhang
// Date:   2021-05-20

class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int origin = 0;
        vector<double> tans;
        for (auto& p: points) {
            if (p[0] == location[0] && p[1] == location[1]) {
                origin++;
            } else {
                tans.push_back(atan2(p[1] -  location[1], p[0] - location[0]));
            }
        }
        sort(tans.begin(), tans.end());
        int n = tans.size();
        for (int i = 0; i < n; i++) {
            tans.push_back(tans[i] + 2.0 * M_PI);
        }
        int l = 0;
        int res = 0;
        double scope = angle * M_PI / 180.0;
        for (int r = 0; r < tans.size(); r++) {
            while (tans[r] - tans[l] > scope) l++;
            res = max(res, r - l + 1);
        }
        return res + origin;
    }
};
