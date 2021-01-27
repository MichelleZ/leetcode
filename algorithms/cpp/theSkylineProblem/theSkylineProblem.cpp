// Source: https://leetcode.com/problems/the-skyline-problem/
// Author: Miao Zhang
// Date:   2021-01-27

/***************************************************************
 * From left to right. If left, put height to heap;
 * If right, delete height
 * [l, -h], [r, h], -h represents left side
***************************************************************/
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events;
        vector<vector<int>> res;
        multiset<int> mset;
        
        for (const auto& b: buildings) {
            events.push_back({b[0], -b[2]});
            events.push_back({b[1], b[2]});
        }
        sort(events.begin(), events.end());
        
        int pre = 0, cur = 0;
        mset.insert(0);
        for (auto e: events) {
            if (e.second < 0) {                // left side, put height to heap
                mset.insert(-e.second);
            } else {                           // right side, pop
                mset.erase(mset.find(e.second));
            }
            cur = *mset.rbegin();               // cur max height
            if (cur != pre) {
                res.push_back({e.first, cur});
                pre = cur;
            }
        }
        return res;
    }
};
