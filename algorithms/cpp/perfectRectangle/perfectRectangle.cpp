// Source: https://leetcode.com/problems/perfect-rectangle/
// Author: Miao Zhang
// Date:   2021-02-07

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        set<pair<int, int>> corners;
        int area = 0;
        for (auto& rect: rectangles) {
            pair<int, int> p1{rect[0], rect[1]};
            pair<int, int> p2{rect[2], rect[1]};
            pair<int, int> p3{rect[2], rect[3]};
            pair<int, int> p4{rect[0], rect[3]};
            for (auto& p: {p1, p2, p3, p4}) {
                const auto &ret = corners.insert(p);
                if (!ret.second) corners.erase(ret.first);
            }
            area += (p3.first - p1.first) * (p3.second - p1.second);
        }
        if (corners.size() != 4) return false;
        auto &p1 = *begin(corners);
        auto &p3 = *rbegin(corners);
        return area == (p3.first - p1.first) * (p3.second - p1.second);
    }
};
