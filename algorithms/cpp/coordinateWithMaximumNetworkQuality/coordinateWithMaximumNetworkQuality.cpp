// Source: https://leetcode.com/problems/coordinate-with-maximum-network-quality/
// Author: Miao Zhang
// Date:   2021-05-21

class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int n = 50;
        vector<int> res{0, 0};
        int maxs = 0;
        for (int x1 = 0; x1 <= n; x1++) {
            for (int y1 = 0; y1 <= n; y1++) {
                int s = 0;
                for (auto& t: towers) {
                    int x2 = t[0], y2 = t[1];
                    float d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
                    if (d <=  radius) {
                        s += floor(t[2] / (d + 1));
                    }
                }
                if (s > maxs) {
                    maxs = s;
                    res = {x1, y1};
                }
            }
        }
        return res;
    }
};
