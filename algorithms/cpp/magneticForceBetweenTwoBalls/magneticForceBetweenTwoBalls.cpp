// Source: https://leetcode.com/problems/magnetic-force-between-two-balls/
// Author: Miao Zhang
// Date:   2021-05-15

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(begin(position), end(position));
        int l = 1;
        int r = position.back();

        auto check = [&] (int x) {
            int pre = position[0];
            int cnt = 1;
            for (int i = 1; i < position.size(); i++) {
                if (position[i] - pre >= x) {
                    pre = position[i];
                    cnt++;
                }
            }
            return cnt >= m;
        };

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (check(mid)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l - 1;
    }
};
