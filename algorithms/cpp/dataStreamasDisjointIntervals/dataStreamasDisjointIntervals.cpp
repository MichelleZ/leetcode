// Source: https://leetcode.com/problems/data-stream-as-disjoint-intervals/
// Author: Miao Zhang
// Date:   2021-02-04

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        vector<int> new_interval{val, val};
        int i;
        int n = intervals.size();
        int overlap = 0;
        for (i = 0; i < n; i++) {
            if (new_interval[1] + 1 < intervals[i][0]) break;
            if (new_interval[0] <= intervals[i][1] + 1) {
                new_interval[0] = min(new_interval[0], intervals[i][0]);
                new_interval[1] = max(new_interval[1], intervals[i][1]);
                overlap++;
            }
        }
        if (overlap > 0) {
            intervals.erase(intervals.begin() + i - overlap, intervals.begin() + i);
        }
        intervals.insert(intervals.begin() + i - overlap, new_interval);
    }
    
    vector<vector<int>> getIntervals() {
        return intervals;
    }

private:
    vector<vector<int>> intervals;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
