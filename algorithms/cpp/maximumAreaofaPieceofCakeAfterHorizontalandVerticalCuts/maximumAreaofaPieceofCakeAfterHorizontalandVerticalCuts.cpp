// Source: https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
// Author: Miao Zhang
// Date:   2021-05-09

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int kMod = 1e9 + 7;
        sort(begin(horizontalCuts), end(horizontalCuts));
        sort(begin(verticalCuts), end(verticalCuts));
        int x = max(horizontalCuts[0], h - horizontalCuts.back());
        int y = max(verticalCuts[0], w - verticalCuts.back());
        for (int i = 1; i < horizontalCuts.size(); i++) {
            x = max(x, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        for (int j = 1; j < verticalCuts.size(); j++) {
            y = max(y, verticalCuts[j] - verticalCuts[j - 1]);
        }
        return static_cast<long>(x) * y % kMod;
    }
};
