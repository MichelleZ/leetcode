// Source: https://leetcode.com/problems/best-position-for-a-service-centre/
// Author: Miao Zhang
// Date:   2021-05-13

class Solution {
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        double eps = 1e-7;
        double alpha = 1;
        double decay = 1e-3;
        
        int n = positions.size();
        int batchSize = n;
        
        double x = 0.0, y = 0.0;
        for (const auto& pos: positions) {
            x += pos[0];
            y += pos[1];
        }
        x /= n;
        y /= n;
        
        auto getDist = [&] (double xc, double yc) {
            double res = 0;
            for (auto& pos: positions) {
                res += sqrt((pos[0] - xc) * (pos[0] - xc) + (pos[1] - yc) * (pos[1] - yc));
            }
            return res;
        };
        
        mt19937 gen{random_device{}()};
        while (true) {
            shuffle(positions.begin(), positions.end(), gen);
            double xPrev = x;
            double yPrev = y;
            for (int i = 0; i < n; i += batchSize) {
                int j = min(i + batchSize, n);
                double dx = 0.0, dy = 0.0;
                for (int k = i; k < j; k++) {
                    auto& pos = positions[k];
                    dx += (x - pos[0]) / (sqrt((x - pos[0]) * (x - pos[0]) + (y - pos[1]) * (y - pos[1])) + eps);
                    dy += (y - pos[1]) / (sqrt((x - pos[0]) * (x - pos[0]) + (y - pos[1]) * (y - pos[1])) + eps);
                }
                x -= alpha * dx;
                y -= alpha * dy;
                alpha *= (1.0 - decay);
            }
            if (sqrt((x - xPrev) * (x - xPrev) + (y - yPrev) * (y - yPrev)) < eps) {
                break;
            }
        }
        return getDist(x, y);
    }
};
