// Source: https://leetcode.com/problems/minimum-speed-to-arrive-on-time/
// Author: Miao Zhang
// Date:   2021-06-15

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if (hour <= dist.size() - 1) return -1;
        int l = 1, r = *max_element(begin(dist), end(dist)) * 100;
        
        function<bool(double)> cost = [&] (int m) {
            double res = 0;
            for (int i = 0; i < dist.size() - 1; i++) {
                res += (dist[i] + m - 1) / m;
                if (res > hour) return true;
            }
            res += (double)dist.back() / m;
            if (res > hour) return true;
            return false;
        };
        
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (cost(mid)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l == 1e9 ? -1 : l;
    }
};
