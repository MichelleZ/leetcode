// Source: https://leetcode.com/problems/find-right-interval/
// Author: Miao Zhang
// Date:   2021-02-11

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> res, starts;
        unordered_map<int, int> m;
        for (int i = 0; i < intervals.size(); i++) {
            m[intervals[i][0]] = i;
            starts.push_back(intervals[i][0]);
        }
        sort(starts.rbegin(), starts.rend());
        for (auto it: intervals) {
            int i = 0;
            for (; i < starts.size(); i++) {
                if (it[1] > starts[i]) break;
            }
            res.push_back((i > 0) ? m[starts[i - 1]] : -1);
        }
        return res;
    }
};

/***********************************************************
***********************************************************/
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> res;
        map<int, int> m;
        for (int i = 0; i < intervals.size(); i++) {
            m[intervals[i][0]] = i;
        }
        for (auto itv: intervals) {
            auto it = m.lower_bound(itv[1]);
            if (it == m.end()) {
                res.push_back(-1);
            } else {
                res.push_back(it->second);
            }
        }
        return res;
    }
};
